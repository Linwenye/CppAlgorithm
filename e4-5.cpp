#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int n_r, n_c, n_operations, n_queries;
    int kase = 0;
    while ((cin >> n_r >> n_c) && !(n_r == 0 && n_c == 0))
    {
        if(kase!=0) cout<<endl;
        vector<vector<string>> table;

        for (size_t i = 0; i < n_r; i++)
        {
            vector<string> table_row;
            for (size_t j = 0; j < n_c; j++)
            {
                table_row.push_back(to_string(i+1) + "," + to_string(j+1));
            }
            table.push_back(table_row);
        }

        cin >> n_operations;
        string operation;
        for (size_t p = 0; p < n_operations; p++)
        {
            cin >> operation;
            if (operation == "EX")
            {
                int r1, c1, r2, c2;
                cin >> r1 >> c1 >> r2 >> c2;
                swap(table[r1 - 1][c1 - 1], table[r2 - 1][c2 - 1]);
            }
            else
            {
                int k;
                cin >> k;
                vector<int> k_opers;
                int oper;
                for (size_t i = 0; i < k; i++)
                {
                    cin >> oper;
                    k_opers.push_back(oper);
                }
                sort(k_opers.begin(), k_opers.end());
                if (operation == "IR")
                {
                    for (size_t i = 0; i < k; i++)
                    {
                        k_opers[i] += i - 1;
                    }
                    for (size_t i = 0; i < k; i++)
                    {
                        vector<string> to_insert(table[0].size(), "");
                        table.insert(table.begin() + k_opers[i], to_insert);
                    }
                }
                else if (operation == "IC")
                {
                    for (size_t i = 0; i < k; i++)
                    {
                        k_opers[i] += i - 1;
                    }
                    for (size_t j = 0; j < k; j++)
                    {
                        for (size_t i = 0; i < table.size(); i++)
                        {
                            table[i].insert(table[i].begin() + k_opers[j], "");
                        }
                    }
                }
                else if (operation == "DR")
                {
                    for (size_t i = 0; i < k; i++)
                    {
                        k_opers[i] = k_opers[i] - 1 - i;
                    }
                    for (size_t i = 0; i < k; i++)
                    {
                        table.erase(table.begin() + k_opers[i]);
                    }
                }
                else if (operation == "DC")
                {
                    for (size_t i = 0; i < k; i++)
                    {
                        k_opers[i] = k_opers[i] - 1 - i;
                    }
                    for (size_t j = 0; j < k; j++)
                    {
                        for (size_t i = 0; i < table.size(); i++)
                        {
                            table[i].erase(table[i].begin() + k_opers[j]);
                        }
                    }
                }
            }
        }

        map<string,string> res;
        for (size_t i = 0; i < table.size(); i++)
        {
            for (size_t j = 0; j < table[0].size(); j++)
            {
                res[table[i][j]]=to_string(i+1)+","+to_string(j+1);
            }
        }
        
        cout<<"Spreadsheet #"<<++kase<<endl;
        cin >> n_queries;
        int r, c;
        for (size_t i = 0; i < n_queries; i++)
        {
            cin>>r>>c;
            string query_str= to_string(r)+","+to_string(c);
            if(res.count(query_str)!=0){
                cout<<"Cell data in ("<<query_str<<") moved to ("<<res[query_str]<<")"<<endl;
            }
            else
            {
                cout<<"Cell data in ("<<query_str<<") GONE"<<endl;
            }
            
        }
    }
}
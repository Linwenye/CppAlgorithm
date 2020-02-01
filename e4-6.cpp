#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

#define EPS 0.00001

using namespace std;

struct Student
{
    int rank;
    string sid;
    int cid;
    string name;
    int chinese;
    int math;
    int english;
    int program;
    int total;
    double average;
};

vector<Student> students;
int statistics(int &sum, int per_grade, int &pass, int &fail);

int main()
{
    cout << "Welcome to Student Performance Management System (SPMS).\n\n1 - Add\n2 - Remove\n3 - Query\n4 - Show ranking\n5 - Show Statistics\n0 - Exit\n"
         << endl;
    int choice;
    while (cin >> choice && choice)
    {
        switch (choice)
        {
        case 1: // add
        {
            while (true)
            {
                cout << "Please enter the SID, CID, name and four scores. Enter 0 to finish." << endl;

                Student stud;
                cin >> stud.sid;
                if (stud.sid == "0")
                {
                    break;
                }
                cin >> stud.cid >> stud.name >> stud.chinese >> stud.math >> stud.english >> stud.program;
                stud.total = stud.chinese + stud.math + stud.english + stud.program;
                stud.average = stud.total / 4.0;

                int rank = 1;
                bool duplicate = false;
                for (size_t i = 0; i < students.size(); i++)
                {
                    if (stud.sid == students[i].sid)
                    {
                        duplicate = true;
                        break;
                    }
                    if (students[i].total > stud.total)
                    {
                        rank++;
                    }
                }
                if (duplicate)
                {
                    cout << "Duplicated SID." << endl;
                }
                else
                {
                    stud.rank = rank;
                    students.push_back(stud);
                }
            }

            break;
        }
        case 2: //remove
        {
            string to_delete;
            while (true)
            {
                int delete_n = 0;
                cout << "Please enter SID or name. Enter 0 to finish." << endl;
                cin >> to_delete;
                if (to_delete == "0")
                {
                    break;
                }
                auto it = students.begin();
                while (it != students.end())
                {
                    if ((*it).sid == to_delete || (*it).name == to_delete)
                    {
                        it = students.erase(it);
                        delete_n++;
                    }
                    else
                    {
                        it++;
                    }
                }
                cout << delete_n << " student(s) removed." << endl;
            }

            break;
        }
        case 3: //query
        {

            string query;
            while (true)
            {
                cout << "Please enter SID or name. Enter 0 to finish." << endl;
                cin >> query;
                if (query == "0")
                {
                    break;
                }
                for (auto &&stud : students)
                {
                    if (stud.sid == query || stud.name == query)
                    {
                        cout << stud.rank << " " << stud.sid << " " << stud.cid << " " << stud.name << " ";
                        printf("%d %d %d %d %d %.2lf\n", stud.chinese, stud.math, stud.english, stud.program, stud.total, stud.average + EPS);
                    }
                }
            }

            break;
        }
        case 4: //rank
            cout << "Showing the ranklist hurts students’ self-esteem. Don’t do that." << endl;
            break;
        case 5: //statistics
        {
            cout << "Please enter class ID, 0 for the whole statistics." << endl;
            int cid;
            cin >> cid;

            int c_sum = 0;
            int cp = 0, cf = 0;
            int m_sum = 0;
            int mp = 0, mf = 0;
            int e_sum = 0;
            int ep = 0, ef = 0;
            int p_sum = 0;
            int pp = 0, pf = 0;

            int n_all = 0;
            int pass_n[5] = {0, 0, 0, 0, 0};

            for (auto &&stud : students)
            {
                if (stud.cid == cid || cid == 0)
                {
                    n_all++;
                    int he_pass = 0;
                    he_pass = statistics(c_sum, stud.chinese, cp, cf) +
                              statistics(m_sum, stud.math, mp, mf) +
                              statistics(e_sum, stud.english, ep, ef) +
                              statistics(p_sum, stud.program, pp, pf);
                    for (int i = 1; i < 5; i++)
                    {
                        if (he_pass >= i)
                        {
                            pass_n[i]++;
                        }
                    }
                    if (he_pass == 0)
                    {
                        pass_n[0]++;
                    }
                }
            }
            printf("Chinese\nAverage Score: %.2lf\nNumber of passed students: %d\nNumber of failed students: %d\n\n"
                   "Mathematics\nAverage Score: %.2lf\nNumber of passed students: %d\nNumber of failed students: %d\n\n"
                   "English\nAverage Score: %.2lf\nNumber of passed students: %d\nNumber of failed students: %d\n\n"
                   "Programming\nAverage Score: %.2lf\nNumber of passed students: %d\nNumber of failed students: %d\n\n"
                   "Overall:\nNumber of students who passed all subjects: %d\n"
                   "Number of students who passed 3 or more subjects: %d\nNumber of students who passed 2 or more subjects: %d\n"
                   "Number of students who passed 1 or more subjects: %d\nNumber of students who failed all subjects: %d\n\n",
                   c_sum / double(n_all) + EPS, cp, cf, m_sum / double(n_all) + EPS, mp, mf, e_sum / double(n_all) + EPS, ep, ef, p_sum / double(n_all) + EPS, pp, pf, pass_n[4], pass_n[3], pass_n[2], pass_n[1], pass_n[0]);
            break;
        }
        }
        cout << "Welcome to Student Performance Management System (SPMS).\n\n1 - Add\n2 - Remove\n3 - Query\n4 - Show ranking\n5 - Show Statistics\n0 - Exit\n"
             << endl;
    }
}

// return pass 1 or 0
int statistics(int &sum, int per_grade, int &pass, int &fail)
{
    sum += per_grade;
    if (per_grade >= 60)
    {
        pass++;
        return 1;
    }
    else
    {
        fail++;
        return 0;
    }
}
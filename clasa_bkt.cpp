#include <iostream>

using namespace std;

class bkt {
protected:
    int st[20], k, max_sol;
    virtual void init() { };
    virtual bool solutie() = 0;
    virtual bool valid() = 0;
    virtual bool succesor() = 0;
    virtual void print() {
        for(int i=1; i<=max_sol; i++)
            cout << st[i] << ' ';
        cout << endl;
    }

public:
    void run() {
        bool succ;
        k = 1;
        init();
        while(k > 0){
            do {
                succ = succesor();
            }while(succ && !valid());
            if(succ)
                if(solutie())
                    print();
                else {
                    k++;
                    init();
                }
            else
                k--;
        }
    }
};

class perm : public bkt {
public:
    perm(int x) { max_sol = x; }
    virtual void init() {
        st[k] = 0;
        cout << k << "init \n";
    }
    virtual bool succesor() {
        if(st[k] < max_sol){
            st[k]++;
            return true;
        }
        return false;
    }
    virtual bool valid() {
        for(int i=1; i<k; i++)
            if(st[k] == st[i])
                return false;
        return true;
    }
    virtual bool solutie() {
        return k == max_sol;
    }

};



int main()
{
    perm p(3);
    p.run();
}

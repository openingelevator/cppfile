#include <iostream>
#include <vector>
using namespace std;

// ����һ��ʵ�ʵ���
class Obj {
    static int i, j;
public:
    void f() const { cout << i++ << endl; }
    void g() const { cout << j++ << endl; }
};

// ��̬��Ա����
int Obj::i = 10;
int Obj::j = 12;

// Ϊ�������ʵ��һ������
class ObjContainer {
    vector<Obj*> a;
public:
    void add(Obj* obj)
    {
        a.push_back(obj);  // ���������ı�׼����
    }
    friend class SmartPointer;
};

// ʵ������ָ�룬���ڷ����� Obj �ĳ�Ա
class SmartPointer {
    ObjContainer oc;
    int index;
public:
    SmartPointer(ObjContainer& objc)
    {
        oc = objc;
        index = 0;
    }
    // ����ֵ��ʾ�б����
    bool operator++() // ǰ׺�汾
    {
        if (index >= oc.a.size() - 1) return false;
        if (oc.a[++index] == 0) return false;
        return true;
    }
    bool operator++(int) // ��׺�汾
    {
        return operator++();
    }
    // ��������� ->
    Obj* operator->() const
    {
        if (!oc.a[index])
        {
            cout << "Zero value";
            return (Obj*)0;
        }
        return oc.a[index];
    }
};

int main() {
    const int sz = 10;
    Obj o[sz];
    ObjContainer oc;
    for (int i = 0; i < sz; i++)
    {
        oc.add(&o[i]);
    }
    SmartPointer sp(oc); // ����һ��������
    do {
        sp->f(); // ����ָ�����
        sp->g();
    } while (sp++);
    return 0;
}
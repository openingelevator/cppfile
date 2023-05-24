#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include<algorithm>
#include<iomanip>

using namespace std;

vector<int> generateInstructionSequence() {
    vector<int> instructions;
    int m = 0;
    srand(static_cast<unsigned int>(time(0))); 
    m = rand()%319;
    for (int i = 0; i < 320; i++) {
        if(i%2==0){
            // ˳��ִ��һ��ָ���ִ�е�ַΪm+1��ָ��
            instructions.push_back(m+1); 
        }
        else if(i%4==1){
            // ��ǰ��ַ[0��m+1]�����ѡȡһ��ָ�ִ��,��ָ��ĵ�ַΪm��
            // ˳��ִ��һ��ָ����ַΪ m��+ 1
            m = rand() % (m + 1);
            instructions.push_back(m);
        }else if(i%4==3){
            // �ں��ַ[m��+ 2��319]�����ѡȡһ��ָ�ִ��
            m = (rand() % (320 - m - 2) + m + 2)%320;
            instructions.push_back(m);
            m = rand()%319;
        }
    }

    return instructions;
}

vector<int> convertToPageAddressStream(const vector<int>& instructions, int pageSize) {
    vector<int> pageStream;
    int pageCount = instructions.size();
    for (int i = 0; i < pageCount; i++) {
       pageStream.push_back(instructions[i]/10);
    }
    return pageStream;
}
// �Ƚ��ȳ��㷨 (FIFO)
double FIFO(const vector<int>& pageStream, int memoryCapacity) {
    vector<int> memory(memoryCapacity, -1);
    int pageFaults = 0;

    for (int i = 0; i < 320; i++) {
        int page = pageStream[i];
        if (find(memory.begin(), memory.end(), page) == memory.end()) {
            // ҳ�治���ڴ��У�����ҳ��ʧЧ
            pageFaults++;
            if (memory.size() == memoryCapacity) {
                // �ڴ�������ʹ��FIFO�㷨��̭���Ƚ����ڴ��ҳ��
                memory.erase(memory.begin());
            }
            memory.push_back(page);
        }
    }
    // for(auto i :memory){
    //     cout<<i<<endl;
    // }
    double hitRate = 1.0 - (static_cast<double>(pageFaults) / 320.0);
    return hitRate;
}

// �������ʹ���㷨 (LRU)
double LRU(const vector<int>& pageStream, int memoryCapacity) {
    vector<int> memory(memoryCapacity, -1);
    vector<int> accessTime(memoryCapacity, 0);
    int pageFaults = 0;

    for (int i = 0; i < 320; i++) {
        int page = pageStream[i];
        auto it = find(memory.begin(), memory.end(), page);
        if (it == memory.end()) {
            // ҳ�治���ڴ��У�����ҳ��ʧЧ
            pageFaults++;
            if (memory.size() == memoryCapacity) {
                // �ڴ�������ʹ��LRU�㷨��̭�������ʹ�õ�ҳ��
                int minAccessTime = *min_element(accessTime.begin(), accessTime.end());
                it = find(accessTime.begin(), accessTime.end(), minAccessTime);
                int index = distance(accessTime.begin(), it);
                memory.erase(memory.begin() + index);
                accessTime.erase(accessTime.begin() + index);
            }
            memory.push_back(page);
            accessTime.push_back(i);
        } else {
            // ҳ�����ڴ��У����·���ʱ��
            int index = distance(memory.begin(), it);
            accessTime[index] = i;
        }
    }
    // for(auto i :memory){
    //     cout<<i<<endl;
    // }
    double hitRate = 1.0 - (static_cast<double>(pageFaults) / 320.0);
    return hitRate;
}
// �����̭�㷨 (OPT)
double OPT(const vector<int>& pageStream, int memoryCapacity) {
    vector<int> memory(memoryCapacity, -1);
    int pageFaults = 0;

    for (int i = 0; i < 320; i++) {
        int page = pageStream[i];
        if (find(memory.begin(), memory.end(), page) == memory.end()) {
            // ҳ�治���ڴ��У�����ҳ��ʧЧ
            pageFaults++;
            if (memory.size() == memoryCapacity) {
                // �ڴ�������ʹ��OPT�㷨��̭�ʱ���ڲ�ʹ�õ�ҳ��
                int maxDistance = 0;
                int pageToReplace = -1;
                // ���ڴ���ÿһ��ҳ��ţ���֮���ָ��������Ѱ�Ҹ�ҳ����һ�γ���ʱ��ƫ����
                // ƫ�������ı�ʾ��ҳ�����ʱ���ڲ�ʹ��
                for (int j = 0; j < memory.size(); j++) {
                    bool found = false;
                    for (int k = i + 1; k < 320; k++) {
                        if (memory[j] == pageStream[k]) {
                            found = true;
                            if (k > maxDistance) {
                                maxDistance = k;
                                pageToReplace = j;
                            }
                            break;
                        }
                    }
                    if (!found) {
                        pageToReplace = j;
                        break;
                    }
                }
                memory[pageToReplace] = page;
            } else {
                memory.push_back(page);
            }
        }
    }
    // for(auto i :memory){
    //     cout<<i<<endl;
    // }
    double hitRate = 1.0 - (static_cast<double>(pageFaults) / 320.0);
    return hitRate;
}

double NRU(const vector<int>& pageStream, int memoryCapacity) {
    vector<int> memory(memoryCapacity, -1);
    vector<int> referenceBits(memoryCapacity, 0);
    vector<int> modifyBits(memoryCapacity, 0);
    int pageFaults = 0;

    for (int i = 0; i < 320; i++) {
        int page = pageStream[i];
        auto it = find(memory.begin(), memory.end(), page);
        if (it == memory.end()) {
            // ҳ�治���ڴ��У�����ҳ��ʧЧ
            pageFaults++;
            if (memory.size() == memoryCapacity) {
                // �ڴ�������ʹ��NRU�㷨ѡ��һ��δ��������δ���޸ĵ�ҳ��
                int pageToReplace = -1;
                bool found = false;
                while (!found)
                {
                    for (int j = 0; j < memory.size(); j++) {
                        if (referenceBits[j] == 0 && modifyBits[j] == 0) {
                            pageToReplace = j;
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                    for (int j = 0; j < memory.size(); j++) {
                        if (referenceBits[j] == 0 && modifyBits[j] == 1) {
                            pageToReplace = j;
                            found = true;
                            break;
                        }else if(referenceBits[j] == 1){
                            referenceBits[j]=0;
                        }
                    }
                    }
                }
                memory[pageToReplace] = page;
                referenceBits[pageToReplace] = 1;
                modifyBits[pageToReplace] = 0;
            } else {
                memory.push_back(page);
                referenceBits.push_back(1);
                modifyBits.push_back(0);
            }
        } else {
            // ҳ�����ڴ��У���������λ
            int index = distance(memory.begin(), it);
            referenceBits[index] = 1;
        }
    }

    double hitRate = 1.0 - (static_cast<double>(pageFaults) / 320.0);
    return hitRate;
}
int main() {
    vector<int> instructionSequence = generateInstructionSequence();
    vector<int> pageAddressStream = convertToPageAddressStream(instructionSequence, 10);

    cout << "Instruction Sequence:" << std::endl;
    for (int instruction : instructionSequence) {
        cout << instruction << " ";
    }
    cout << endl;

    cout << "Page Address Stream:" <<endl;
    for (int pageAddress : pageAddressStream) {
        cout << pageAddress << " ";
    }
    cout << endl;

    cout << "�ڴ�����\tFIFO������\tLRU������\tOPT������\tNRU������" << endl;
    for (int memoryCapacity = 4; memoryCapacity <= 32; memoryCapacity++) {
        double fifoHitRate = FIFO(pageAddressStream, memoryCapacity);
        double lruHitRate = LRU(pageAddressStream, memoryCapacity);
        double optHitRate = OPT(pageAddressStream, memoryCapacity);
        double nruHitRate = NRU(pageAddressStream, memoryCapacity);
        cout<<setprecision(4)<<fixed;
        cout << memoryCapacity << "\t\t" << fifoHitRate << "\t\t" << lruHitRate << "\t\t" << optHitRate << "\t\t" <<nruHitRate<< endl;
    }
    system("pause");
    return 0;
}
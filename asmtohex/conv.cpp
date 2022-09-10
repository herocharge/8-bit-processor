#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <limits>
using namespace std;

uint8_t conv_to_byte(string s){
    if(s.length() == 0)return 0;
    if(s.length() < 2){return stoi(s);}
    if(s[0] == '0' && s[1] == 'x'){
        return stoi(s, 0, 16);
    }
    return stoi(s);
}

int main(int argc, char** argv){
    vector<string> instructions = {"NOP", "MOVAA", "MOVAB", "MOVAC", "MOVAD", "MOVAE", "MOVAH", "MOVAL", "MOVAM", "LDAXB", "LDAXD", "LDA", "MOVBA", "MOVBB", "MOVBC", "MOVBD", "MOVBE", "MOVBH", "MOVBL", "MOVBM", "MOVCA", "MOVCB", "MOVCC", "MOVCD", "MOVCE", "MOVCH", "MOVCL", "MOVCM", "MOVDA", "MOVDB", "MOVDC", "MOVDD", "MOVDE", "MOVDH", "MOVDL", "MOVDM", "MOVEA", "MOVEB", "MOVEC", "MOVED", "MOVEE", "MOVEH", "MOVEL", "MOVEM", "MOVHA", "MOVHB", "MOVHC", "MOVHD", "MOVHE", "MOVHH", "MOVHL", "MOVHM", "MOVLA", "MOVLB", "MOVLC", "MOVLD", "MOVLE", "MOVLH", "MOVLL", "MOVLM", "MOVMA", "MOVMB", "MOVMC", "MOVMD", "MOVME", "MOVMH", "MOVML", "MVIA", "MVIB", "MVIC", "MVID", "MVIE", "MVIH", "MVIL", "MVIM", "STAXB", "STAXD", "STA", "LXIBC", "LXIDE", "LXIHL", "LXISP", "XCHNG", "XTHL", "ADDA", "ADDB", "ADDC", "ADDD", "ADDE", "ADDH", "ADDL", "ADDM", "ADI", "ADCA", "ADCB", "ADCC", "ADCD", "ADCE", "ADCH", "ADCL", "ADCM", "ACI", "SUBA", "SUBB", "SUBC", "SUBD", "SUBE", "SUBH", "SUBL", "SUBM", "SUI", "SBBA", "SBBB", "SBBC", "SBBD", "SBBE", "SBBH", "SBBL", "SBBM", "SBI", "DADBC", "DADDE", "DADHL", "DADSP", "INRA", "INRB", "INRC", "INRD", "INRE", "INRH", "INRL", "INRM", "DCRA", "DCRB", "DCRC", "DCRD", "DCRE", "DCRH", "DCRL", "DCRM", "INXBC", "INXDE", "INXHL", "INXSP", "DCXBC", "DCXDE", "DCXHL", "DCXSP", "RLC", "RRC", "RAL", "RAR", "ANAA", "ANAB", "ANAC", "ANAD", "ANAE", "ANAH", "ANAL", "ANAM", "ANI", "XRAA", "XRAB", "XRAC", "XRAD", "XRAE", "XRAH", "XRAL", "XRAM", "XRI", "ORAA", "ORAB", "ORAC", "ORAD", "ORAE", "ORAH", "ORAL", "ORAM", "ORI", "CMPA", "CMPB", "CMPC", "CMPD", "CMPE", "CMPH", "CMPL", "CMPM", "CPI", "JMP", "JNZ", "JZ", "JNC", "JC", "JPO", "JPE", "JP", "JM", "PCHL", "CALL", "CNZ", "CZ", "CNC", "CC", "RET"};
    vector<uint8_t> opcodes = {
        0x00, 0x7F, 0x78, 0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0x0A, 0x1A, 0x3A, 0x47, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x4F, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x57, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x5F, 0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x67, 0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x6F, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x77, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x3E, 0x06, 0x0E, 0x16, 0x1E, 0x26, 0x2E, 0x36, 0x02, 0x12, 0x32, 0x01, 0x11, 0x21, 0x31, 0xEB, 0xE3, 0x87, 0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0xC6, 0x8F, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0xCE, 0x97, 0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0xD6, 0x9F, 0x98, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0xDE, 0x09, 0x19, 0x29, 0x39, 0x3C, 0x04, 0x0C, 0x14, 0x1C, 0x24, 0x2C, 0x34, 0x3D, 0x05, 0x0D, 0x15, 0x1D, 0x25, 0x2D, 0x35, 0x03, 0x13, 0x23, 0x33, 0x0B, 0x1B, 0x2B, 0x3B, 0x07, 0x0F, 0x17, 0x1F, 0xA7, 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xE6, 0xAF, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xEE, 0xB7, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xF6, 0xBF, 0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xFE, 0xC3, 0xC2, 0xCA, 0xD2, 0xDA, 0xE2, 0xEA, 0xF2, 0xFA, 0xE9, 0XCD, 0xC4, 0xCC, 0xD4, 0xDC, 0xC9
    };
    int n = instructions.size();
    map<string, uint8_t> mp;
    for(int i = 0; i < n; i++){
        mp[instructions[i]] = opcodes[i];
    }
    if(argc != 3){
        cout<<"Usage:"<<(argv[0])<<"<input_file_name> <output_file_name>"<<endl;
    }
    ifstream input_file(argv[1]);
    ofstream output_file(argv[2], ios::binary | ios::out);
    vector<uint8_t> byts;
    while(input_file.peek() != EOF){
        string s;
        input_file>>s;
        if(s.length() == 0)continue;
        if(s[0] == ';' || s[0] == '#'){
            input_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if(s != "NOP" && mp[s] == 0){
            if(s.length() == 1)if(!isdigit(s[0])){
                cout<<"Invalid command "<<s<<endl;
                break;
            }
            int start = 0;
            if(s[0] == '0' && s[0] == 'x')start = 2;
            bool flag = true;
            for(int i = start; i < s.length(); i++){
                if(!isdigit(s[i])){
                    flag = false;
                    break;
                }
            }
            if(!flag){
                cout<<"Invalid command "<<s<<endl;
                break;
            }
            byts.push_back(conv_to_byte(s));
        }
        else{
            byts.push_back(mp[s]);
        }
    }
    uint8_t arr[byts.size()];
    for(int i = 0; i < byts.size(); i++){
        arr[i] = byts[i];
    }
    output_file.write((char *) arr, byts.size());
    input_file.close();
    output_file.close();
}
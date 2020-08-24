#include "cipher.hpp"
class cipher{
public:
    cipher(size_t rot=9):rotate(rot%26){}

    std::string encrypt(const std::string& origin){
        if(origin.size()<=0 || rotate == 0){
            return std::string(origin);
        }
        std::string result;
        for(const char &a:origin){
            if(!isalpha(a)){
                result+=a;
                continue;
            }
            int position=(tolower(a)-'a'+rotate)%26;
            if(isupper(a)){
                result+=toupper(lower[position]);
            }else{
                result+=lower[position];
            }
        }
        return result;
    }

    std::string decrypt(const std::string& code);
private:
    size_t rotate;
    std::string lower="abcdefghijklmnopqrstuvwxyz";
};

std::string cipher::decrypt(const std::string& code){
    if(code.size() <= 0 || rotate<=0){
        return std::string(code);
    }
    std::string result;
    for(const char &a:code){
        int position=(a-'a'-rotate+26)%26;
        if(!isalpha(a)){
            result+=a;
            continue;
        }
        if(isupper(a)){
            result+=toupper(lower[position]);
        }else{
            result+=lower[position];
        }
    }
    return result;
}

namespace CipherTest{
    void cipherTest(){
        std::cout<<"this is cipherTest --->"<<std::endl;
        std::string temp="zhangsan";
        std::cout<<"the original string is: "<<temp<<std::endl;
        cipher ciph;
        std::cout<<"after encoding the string is:"<<ciph.encrypt(temp)<<std::endl;
        std::cout<<"after decoding the string is:"<<ciph.decrypt(ciph.encrypt(temp))<<std::endl;
    }
}
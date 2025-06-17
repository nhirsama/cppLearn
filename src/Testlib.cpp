#include<iostream>
#include<vector>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<cstdint>
#define ROTL(x,n)(((x) << (n)) | ((x) >> (32 - (n))))
#define P0(X)(X^ROTL(X,9)^ROTL(X,17))
#define P1(x)(x^ROTL(x,15)^ROTL(x,23))

const uint32_t IV[8]={0x7380166F, 0x4914B2B9, 0x172442D7, 0xDA8A0600,0xA96F30BC, 0x163138AA, 0xE38DEE4D, 0xB0FB0E4E};
const uint32_t T[64]={0x79CC4519, 0x79CC4519, 0x79CC4519, 0x79CC4519,
    0x79CC4519, 0x79CC4519, 0x79CC4519, 0x79CC4519,
    0x79CC4519, 0x79CC4519, 0x79CC4519, 0x79CC4519,
    0x79CC4519, 0x79CC4519, 0x79CC4519, 0x79CC4519,
  0x7A879D8A, 0x7A879D8A, 0x7A879D8A, 0x7A879D8A,
    0x7A879D8A, 0x7A879D8A, 0x7A879D8A, 0x7A879D8A,
    0x7A879D8A, 0x7A879D8A, 0x7A879D8A, 0x7A879D8A,
    0x7A879D8A, 0x7A879D8A, 0x7A879D8A, 0x7A879D8A,
    0x7A879D8A, 0x7A879D8A, 0x7A879D8A, 0x7A879D8A,
    0x7A879D8A, 0x7A879D8A, 0x7A879D8A, 0x7A879D8A,
    0x7A879D8A, 0x7A879D8A, 0x7A879D8A, 0x7A879D8A,
    0x7A879D8A, 0x7A879D8A, 0x7A879D8A, 0x7A879D8A,
    0x7A879D8A, 0x7A879D8A, 0x7A879D8A, 0x7A879D8A,
    0x7A879D8A, 0x7A879D8A, 0x7A879D8A, 0x7A879D8A,
    0x7A879D8A, 0x7A879D8A, 0x7A879D8A, 0x7A879D8A,  
    0x7A879D8A, 0x7A879D8A, 0x7A879D8A, 0x7A879D8A
};
void sm3_padding(const std::vector<uint8_t>&unpadded_msg,std::vector<uint8_t>&padded_msg){
  uint64_t msg_len=unpadded_msg.size()*8;
  padded_msg=unpadded_msg;
  padded_msg.push_back(0x80);
  while(padded_msg.size()%64!=56)
{padded_msg.push_back(0x00);}
for(int i =7;i>=0;i--){padded_msg.push_back((msg_len>>(i*8))&0xFF);}
}
void sm3_expand(const uint32_t* block,uint32_t* W,uint32_t* W_Prime){
  for(int i=0;i<16;i++){W[i]=block[i];}
  for(int i=16;i<68;i++)
    {uint32_t temp=W[i-16]^W[i-9]^ROTL(W[i-3],15);//chaocausing
    W[i]=P1(temp)^ROTL(W[i-13],7)^W[i-6];}//chaocausing
    for(int i=0;i<64;i++)
      {W_Prime[i]=W[i]^W[i+4];}
}

void Compress(uint32_t*V,uint32_t*W,uint32_t*W_prime){
  uint32_t A=V[0];uint32_t B=V[1];uint32_t C=V[2];uint32_t D=V[3];uint32_t E=V[4];uint32_t F=V[5];uint32_t G=V[6];uint32_t H=V[7];
  for(int j=0;j<64;j++) {
    uint32_t FF=(j<16)?(A^B^C):((A&B)|(A&C)|(B&C));
    uint32_t GG=(j<16)?(E^F^G):((E&F)|((~E)&G));
    uint32_t SS1=ROTL((ROTL(A,12)+E+ROTL(T[j],j%32)),7);
    uint32_t SS2=SS1^ROTL(A,12);
    uint32_t TT1=FF+D+SS2+W_prime[j];
    uint32_t TT2=GG+H+SS1+W[j];
    D=C;C=ROTL(B,9);B=A;A=TT1;H=G;G=ROTL(F,19);F=E;E=P0(TT2);
  }
  V[0]^=A;V[1]^=B;V[2]^=C;V[3]^=D;V[4]^=E;
  V[5]^=F;V[6]^=G;V[7]^=H;

  }
void SM3_Hash(const std::vector<uint8_t>&message,std::vector<uint8_t>&hash){
  std::vector<uint8_t>padded_msg;
  sm3_padding(message,padded_msg);
  uint32_t V[8];
  std::memcpy(V,IV,sizeof(IV));
  for(size_t i=0;i<padded_msg.size();i+=64)
{uint32_t block[16]={0};uint32_t W[68]={0};uint32_t W_prime[64]={0};
for(int j=0;j<16&&(i+j*4+3)<padded_msg.size();j++){block[j]=(padded_msg[i+j*4]<<24)|(padded_msg[i+j*4+1]<<16)|(padded_msg[i+j*4+2]<<8)|(padded_msg[i+j*4+3]);}
sm3_expand(block,W,W_prime);Compress(V,W,W_prime);
}
hash.resize(32);
for(int i=0;i<8;i++){
  hash[i*4]=(V[i]>>24)&0xFF;
  hash[i*4+1]=(V[i]>>16)&0xFF;
  hash[i*4+2]=(V[i]>>8)&0xFF;
  hash[i*4+3]=(V[i]&0xFF);
}}
int main(){
std::string input;
std::getline(std::cin,input);
std::vector<uint8_t>message(input.begin(),input.end());std::vector<uint8_t>hash;
SM3_Hash(message,hash);
std::cout<<"Hash ";for(uint8_t byte:hash){std::cout<<std::hex<<std::setw(2)<<std::setfill('0')<<(int)byte;}
}

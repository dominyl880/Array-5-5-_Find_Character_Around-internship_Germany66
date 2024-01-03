#include<iostream>
using namespace std;

void CheckAround(string intxt);

char a[5][5]={{'a','b','c','d','e'},
              {'l','m','n','o','f'},
              {'k','p','q','r','g'},
              {'j','s','t','u','h'}, 
              {'i','v','w','x','y'}
};

int main(){

    string data[]={"pqruxw","kpuxy","abcdefgrq","mnorhy","abmnptrod","lmrqtw","abcdefghyxurqpsvi","tplmno"};
    
    for(int h=0;h<8;h++){
        CheckAround(data[h]);
    } 

    return 0;
}
void CheckAround(string intxt){
    char given,next;
    int Row,Col;
    string around;
    bool result=NULL;
    short counter=0;


    int amount;
    amount=intxt.length(); //จำนวนอักษรในข้อความที่ส่งมา

    for(int k=0;k<amount;k++){
            around=""; //สำหรับเก็บตัวอักษรรอบๆ

            given=intxt[k]; //ตัวแรก
            next=intxt[k+1]; //ตัวถัดไป

            if(k+1==amount){  //กรณีถึงตำแหน่งสุดท้าย จะไม่มีตำแหน่งถัดไปให้เช็ค จึงเช็คตัวก่อนหน้าแทน
                next=intxt[k-1];
            }
            
            // หาที่อยู่ตัวอักษรที่รับเข้ามา
            for(int i1=0;i1<sizeof(a)/sizeof(a[0]);i1++){
                for(int p=0;p<sizeof(a[0]);p++){
                    if(a[i1][p]==given){
                        Row=i1;
                        Col=p;
                    }
                }
            }
        
            // หาข้อมูลรอบตัวนั้น มากที่สุดอยู่ที่ 8 จำนวน
            for(int i=0;i<sizeof(a)/sizeof(a[0]);i++){
                for(int p=0;p<sizeof(a[0]);p++){

                    if(i==Row && p==Col){
                        // cout<<"# ";  //ที่อยู่ตัวอักษรตรงกลาง
                    }else if(i==Row-1 && p==Col-1){
                        around+=a[i][p];
                    }else if(i==Row-1 && p==Col){
                        around+=a[i][p];
                    }else if(i==Row-1 && p==Col+1){
                        around+=a[i][p];
                    }else if(i==Row   && p==Col-1){
                        around+=a[i][p];
                    }else if(i==Row && p==Col+1){
                        around+=a[i][p];
                    }else if(i==Row+1 && p==Col-1){
                        around+=a[i][p];
                    }else if(i==Row+1   && p==Col){
                        around+=a[i][p];
                    }else if(i==Row+1 && p==Col+1){
                        around+=a[i][p];
                    }else{
                        // cout<<"0 "; // ไม่เกี่ยวข้อง
                    } 

                } 
            } 
            
              
            for(int q=0;q<around.length();q++){ 
              if(around[q]==next){
                  counter+=1;
                  break; //เจอแล้ว ออกเลย
              }
            }

            if(counter!=intxt.length()){  //ถ้าจำนวนเจอ!=จำนวนที่มี หมายความว่าไม่ได้มีความสัมพันธ์กันทุกตัว
              result=false; 
            }else{
              result=true;
            }

    }
 
    if(result==true){
        cout<<"True ";
    }else{
        cout<<"False ";
    }
}

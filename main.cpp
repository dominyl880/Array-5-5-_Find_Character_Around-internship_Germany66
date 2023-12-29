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
    
    for(int h=0;h<data->length();h++){
        CheckAround(data[h]);
    } 

    return 0;
}
void CheckAround(string intxt){
    char given,next;
    int HereRow=-1,HereCol=-1;
    string around;
    bool result=NULL;

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
                        // cout<<"1 "; 
                        HereRow=i1;
                        HereCol=p;
                    }else{
                        // cout<<"0 "; 
                    }
                }
            }
        
            // หาข้อมูลรอบตัวนั้น มากที่สุดอยู่ที่ 8 จำนวน
            for(int i=0;i<sizeof(a)/sizeof(a[0]);i++){
                for(int p=0;p<sizeof(a[0]);p++){
                    if(i==HereRow && p==HereCol){
                        // cout<<"# ";  //ที่อยู่ตัวอักษรตรงกลาง
                    }else if(i==HereRow-1 && p==HereCol){
                        around+=a[i][p];
                    }else if(i==HereRow+1 && p==HereCol){
                        around+=a[i][p];
                    }else if(i==HereRow-1 && p==HereCol-1){
                        around+=a[i][p];
                    }else if(i==HereRow   && p==HereCol-1){
                        around+=a[i][p];
                    }else if(i==HereRow+1 && p==HereCol-1){
                        around+=a[i][p];
                    }else if(i==HereRow-1 && p==HereCol+1){
                        around+=a[i][p];
                    }else if(i==HereRow   && p==HereCol+1){
                        around+=a[i][p];
                    }else if(i==HereRow+1 && p==HereCol+1){
                        around+=a[i][p];
                    }else{
                        // cout<<"0 "; // ไม่เกี่ยวข้อง
                    } 
                }
                // cout<<endl;
            } 
            
            short counter=0;
              
            for(int q=0;q<around.length();q++){ 
              if(around[q]==next){
                  // cout<<" found!.";
              }else{
                  // cout<<" not."; //นับตัวที่ไม่เจอ ถ้าเท่ากับจำนวนอักษรที่มาในข้อความ หมายความว่า ตัวถัดไป เช็คกับรอบปัจจุบันแล้วไม่มีความสัมพันธ์กัน
                  counter+=1;
              } 
              // cout<<endl;
            }

            if(counter==around.length()){  //ถ้าจำนวนไม่เจอ==จำนวนที่มี หมายความว่าให้ออกเลย ไม่ต้องทำต่อ 
              result=false;
              break;
            }else{
              result=true;
            }

            // if(result==false) break; //ออกไปอีก ไม่ต้องทำชุดถัดไป เพราะมัน เป็นเท็จแล้ว
    }

    // cout<<endl;
    if(result==true){
        cout<<"True ";
    }else{
        cout<<"False ";
    }
}

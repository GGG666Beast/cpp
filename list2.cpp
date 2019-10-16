/*
list2.cc 概要： 学籍番号，名前，姓、期末得点、中間得点、演習得点が記入されたリストを入力し， これを名前，姓，学籍番号、演習総合点、演習平均点、演習メジアン、総合得点の順に出力するプログラム
Author: Kaise Beppu 
Date: 2019-10-10
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<ios>

using namespace std;

int main(){


    string first, last, id;
    vector<double> kadai;
    vector<double>::size_type size2;
    double mid,final,sum,average,median,score;
    int amari;
    const int size=18;
    string frame(size,'=');
    string column(size,'-');
    int cnt=0;

    //フレームの表示
    cout << "+" << frame << "+" << frame << "+" << frame << "+" << "=======+=======+=======+=======+" << endl;

    //ここからデータの読み取り。一つ目のループで期末まで、二つ目のループで演習課題
    while(cin>>first>>last>>id>>mid>>final){

      ++cnt;
      
        sum=0;
	amari=0;
	average=0;

	kadai.clear();
	
        double tmp;
        cin>>tmp;
        while(tmp!=-1){

            kadai.push_back(tmp);
            sum+=tmp;
            cin>>tmp;
        }

        size2=kadai.size();
        average=sum/(double)size2;
        sort(kadai.begin(),kadai.end());

	for(vector<double>::size_type i=0;i<size2;i++) amari+=(int)kadai[i];
	if(amari==0){
	  median=0;
	  average=0;
	}

	else{

        //中央値をしらべる
        amari=(int)size2%2;
        if(amari==1) {
            amari=(int)size2/2;
            median=kadai[amari];
        }
        else{
            amari=(int)size2/2;
            median=(kadai[amari-1]+kadai[amari])/2;
        }
	}
	
        score=mid*0.2+final*0.4+median*0.4;

        string space1(size-first.size()-1,' ');
        cout << "| " <<first <<space1;
        string space2(size-last.size()-1,' ');
        cout << "| " <<last<<space2;
        string space3(size-id.size()-1, ' ');
        cout<<"| "<<id<<space3<<"| ";
	

	
        cout<<setw(5)<<fixed<<setprecision(1)<<setw(6)<<sum<<"|"<<setw(6)<<average<<" |"<<setw(6)<<median<<" |"<<setw(6)<<score<<" |"<<endl;

	if(cnt%5==0){
	  cout<<"+"<<column<<"+"<<column<<"+"<<column<<"+" << "-------+-------+-------+-------+" << cnt << endl;
	}

}
    cout<< "+" << frame << "+" << frame << "+" << frame << "+" << "=======+=======+=======+=======+" << endl;

    return 0;
}
        

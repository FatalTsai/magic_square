//---------------------------------------------------------------------------
#include <cmath>
#include <iostream>

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int square[1386][1386];
int rquare[1386][1386];
int num;

int numDigits(int n) {
    if (n < 10) return 1;
    return 1 + numDigits(n / 10);
}



void generateSquare(int n)
{
	memset(square, 0, sizeof(square));
	int i = n/2;
    int j = n-1;

    // One by one put all values in magic square
    for (int num=1; num <= n*n; )
	{
        if (i==-1 && j==n) //3rd condition
        {
            j = n-2;
            i = 0;
        }
		else
        {
            // 1st condition helper if next number
            // goes to out of square's right side
            if (j == n)
                j = 0;

            // 1st condition helper if next number
            // is goes to out of square's upper side
            if (i < 0)
                i=n-1;
		}
		if (square[i][j]) //2nd condition
        {
            j -= 2;
            i++;
            continue;
        }
		else
			square[i][j] = num++; //set number

        j++; i--; //1st condition
	}
	/*
	// Print magic square
	printf("The Magic Square for n=%d:\nSum of "
       "each row or column %d:\n\n",  n, n*(n*n+1)/2);
	for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
			printf("%3d ", magicSquare[i][j]);
        printf("\n");
	}               */
}

void copy(int n)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			rquare[i][j] =square[i][j];
		}


}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------


void rolate(int n,int time)
{
	copy(num);



	// Consider all squares one by one
	for(int i=0;i<time;i++)
	{
		for (int x = 0; x < n / 2; x++)
		{
			// Consider elements in group of 4 in
			// current square
			for (int y = x; y < n-x-1; y++)
			{
				// store current cell in temp variable
				int temp = rquare[x][y];

				// move values from right to top
				rquare[x][y] = rquare[y][n-1-x];

				// move values from bottom to right
				rquare[y][n-1-x] = rquare[n-1-x][n-1-y];

				// move values from left to bottom
				rquare[n-1-x][n-1-y] = rquare[n-1-y][x];

				// assign temp to left
				rquare[n-1-y][x] = temp;
			}
		}
	}
}



void PrintSquare(int n, int flag)

{    int i, j, k;

	AnsiString row, space ;

	int len = 6;

	int length = numDigits(n*n);
	//Form1->Memo2->Lines->Add(length);

	 if (flag == 1) Form1->Memo1->Lines->Add("    --------- "+IntToStr(n)+"*"+IntToStr(n)+" --------- ");

	 else if (flag == 2) Form1->Memo2->Lines->Add("    --------- "+IntToStr(n)+"*"+IntToStr(n)+" --------- ");

	 for (i = 0; i < n; i++)

	 {   row = "";

		 for (j = 0; j < n; j++)

		 {   space = len - IntToStr(rquare[i][j]).Length();

			 for (k = 0; k < space; k++) row += " ";

			 row += IntToStr(rquare[i][j]);

		 }

		 if (flag == 1) Form1->Memo1->Lines->Add(row);

		 else if (flag == 2) Form1->Memo2->Lines->Add(row);

	 }

}





void __fastcall TForm1::Button2Click(TObject *Sender)
{
   int checked_radio;
   /*
   if(RadioButon1->Checked==true)
	 checked_radio=1;
   else if(RadioButon2->Checked==true)
	 checked_radio=2;
   else if(RadioButon3->Checked==true)
	 checked_radio=3;
   else if(RadioButon4->Checked==true)
	 checked_radio=4;
	 */

	/*
	for(int i=0;i<12;i++){

	 TRadioButton *RadioBtn=(TRadioButton *)FindComponent("R"+(String)(i+1));

	 if(RadioBtn->Checked==true)
		checked_radio=i;
	}
	*/

	rolate(num,checked_radio-1);
	PrintSquare(num,1);



}

//---------------------------------------------------------------------------


void __fastcall TForm1::RadioButton1Click(TObject *Sender)
{


	rolate(num,0);
	PrintSquare(num,2);


}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton2Click(TObject *Sender)
{

	rolate(num,1);
	PrintSquare(num,2);


}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton3Click(TObject *Sender)
{

	rolate(num,2);
	PrintSquare(num,2);


}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton4Click(TObject *Sender)
{

	rolate(num,3);
	PrintSquare(num,2);


}
//---------------------------------------------------------------------------


void check(int n)
{
	int sum =0;

	for(int x=0;x<n;x++)
	{
		 sum=0;
		for(int i=0;i<n;i++){

			sum+=square[x][i];
		}

		Form1->Memo3->Lines->Add("row="+IntToStr(x)+" , "+IntToStr(sum));
	}

	for(int y=0;y<n;y++)
	{
		 sum=0;
		for(int i=0;i<n;i++){

			sum+=square[i][y];
		}

		Form1->Memo3->Lines->Add("col="+IntToStr(y)+" , "+IntToStr(sum));
	}

	sum=0;
	for(int x=0;x<n;x++)
	{


		sum+=square[x][x];



	}
	Form1->Memo3->Lines->Add("cross\\= "+IntToStr(sum));
    sum=0;
	for(int x=0;x<n;x++)
	{


		sum+=square[x][n-1-x];



	}
	Form1->Memo3->Lines->Add("cross/= "+IntToStr(sum));

}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	num =StrToInt(Edit1->Text);
	generateSquare(num);
	copy(num);
	PrintSquare(num,1);
	check(num);


	for(int i=0;i<num;i++)
		 for(int j=0;j<num;j++){


			StringGrid1->Cells[j][i] = IntToStr(square[i][j]);

		 }
}






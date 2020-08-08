/**********************/
/* 演習6-4            */
/* 学籍番号:2021013   */
/* 氏名:王巍錚        */
/* 作成日:2020年8月8日*/
/*********************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void Intro();
int Choice();
void Game();
void Ending(int);
void Fail();
void Enter();
int main()
{
    srand(time(NULL));
    Intro();
    if(Choice()== 1)
        Game();
    return 0;
}

void Intro()
{
    puts("???:起きろ！もう時間はない！(Enterを押して続く)");Enter();
    puts("あなた:お前...誰か");Enter();
    puts("???:お前を救える人だ。暗号を解析できなければ、死ぬぞ");Enter();
    puts("あなた:なに?");Enter();
    puts("???:前にコンピューターがある。問題を解けなければ脱出できない");Enter();
    puts("???生きたいなら、俺の指示を従え！");Enter();
}


int Choice()
{
    int n;
    puts("従うか?");
    puts("1.従う　２.断る");
    while(n != 1 && n != 2)
        scanf("%d",&n);
    if(n == 1)
    {
        Enter();
        puts("???:よし、説明する");Enter();
        puts("x+y+z = 5 x*y*z = 4");
        puts("???:x,y,zの組み合わせは何だ?言ってみろ!");Enter();
        puts("あなた:1 2 2だろう!");Enter();
        puts("???:そうだ。順番が違ってもかまわない。2 1 2を入力しても同じだ。この３つの数字を入力したら生きる、５回間違ったら終わる。");Enter();
        puts("あなた:終わるって...");Enter();
        puts("???:死ぬ!");Enter();
        puts("???:Good Luck!");Enter();
        return 1;
    }

    if(n == 2)
    {
        Fail();
        return 0; 
    }
}
        
void Game()
{
    int life = 4;
    int i;
    int j;
    int sum;
    int product;
    int answersum;
    int answerpro;
    int input[3];
    int pass;
    int x,y,z;
    for(i = 2;i <= 5;i++)
    {    
        pass = 0;
        x = rand() % i + i;
        y = rand() % i + i;
        z = rand() % i + i;
        sum = x+y+z;
        product = x*y*z;
        while(pass != 1 && life >= 0)
        {    
            answersum = 0;
            answerpro = 1;
            puts("");
            printf("%d回残っている...\n",life);
            printf("x+y+z = %d\nx*y*z = %d\n",sum,product);
            puts("x,y,zを入力してください(順番なし)");
           
            for(j = 0;j < 3;j++)
            {
                while(scanf("%d",&input[j]) == 0)
                {
                    Enter();
                }
                answersum += input[j];
                answerpro *= input[j];
                                    
            }
            if(answersum == sum && answerpro == product)
                pass = 1;
            else
                life--;
        }
        if(life < 0)
            break;
    }

    if(life >= 0)
        Ending(life);       
    else
    {
        Fail();
        return;
    }
}

void Ending(int life)
{
    int i;
    int pass = 0;
    int x = rand(); 
    int y = rand();        
    int z = rand();
    int sum = x+y+z;
    int product = x*y*z;
    int answer[3];
    puts("");
    printf("%d回残っている...\n",life);
    printf("x+y+z = %d\nx*y*z = %d\n",sum,product);Enter();
    puts("x,y,zを入力してください(順番なし)");Enter();
    puts("あなた：なんだこれ。人間ができないんだろう！");Enter();
    puts("???：ハハハ！そうだな。お前はもう死んでいる。");Enter();
    puts("???:お前を連れてきたとき、生きてここを出させるつもりはなかったんだ。");Enter();
    puts("???:残念だな。ここで死ね！");Enter();
    puts("あなた:何だ。仲間ではないのか。お前...");Enter();
    puts("扉の鍵をかける音が聞こえた");Enter();
    puts("その後、どこから声がでてきた...");Enter();
    puts("???:生きたいの？");Enter();
    puts("さっきのやつと違った声があった");Enter();
    puts("あなた:絶対生きる。");Enter();
    puts("???:生きたいなら、暗号を思い出してください");Enter();
    puts("???:それが...ファイナルコード!");Enter();
    puts("あなた:それは何だ！");Enter();
    puts("返事も声もない");Enter();
    while(life >= 0)
    {
        puts("");
        printf("%d回残っている...\n",life);
        printf("x+y+z = %d\nx*y*z = %d\n",sum,product);
        puts("x,y,zを入力してください(順番なし)");
        for(i = 0;i < 3;i++)
        {
            while(scanf("%d",&answer[i]) == 0)
            {
                Enter();
            }
        }
        
        if(answer[0] == 2 && answer[1] == 1 && answer[2] == 2)
        {
            puts("扉が開いた。あなたが生きてきた。");
            return;
        }
        else
            life--;
        
    }
    
    Fail();
    return;
}

void Fail()
{
    puts("前のおかしい装置が爆発した、あなたは死んだ");
}

void Enter()
{
    while(getchar() != '\n')
        continue;
}
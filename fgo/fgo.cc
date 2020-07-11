#include "fgo.h"
#include <ctime>
#include <iostream>

void fgo_simulator::showLuck(const int n)
{
    unsigned long long ans = 0;
    for(int i = 1; i <= n/3; ++i)
    {
        ans += memory[i];
    }
    std::cout.precision(2);
    std::cout << n << "개의 돌로, 성공할 확률은" << double(ans)/times*100 << "% 입니다." << '\n';
}

void fgo_simulator::showPercent()
{
    for(int percent = 10; percent < 100; percent+=10)
    {
        unsigned long long ans = 0;
        int i;
        for(i = 1; i < 100000; ++i)
        {
            if(double(ans)/times > double(percent)/100) break;
            ans += memory[i];
        }
        std::cout << percent << "% 확률일 때 필요한 성정석 개수는 " << i*3 << "개입니다." << '\n';
    }
    for(int percent = 91; percent < 100; ++percent)
    {
        unsigned long long ans = 0;
        int i;
        for(i = 1; i < 100000; ++i)
        {
            if(double(ans)/times > double(percent)/100) break;
            ans += memory[i];
        }
        std::cout << percent << "% 확률일 때 필요한 성정석 개수는 " << i*3 << "개입니다." << '\n';
    }
}
void fgo_simulator::summonL4star(const int servent, const int serventNP)
{
    srand(time(NULL));
    totStone = 0;
    std::fill(totLS5, totLS5+LS5, 0);
    std::fill(totLS4, totLS4+LS4, 0);
    std::fill(totLS3, totLS3+LS3, 0);
    std::fill(totLCE5, totLCE5+LCE5, 0);
    std::fill(totLCE4, totLCE4+LCE4, 0);
    std::fill(totLCE3, totLCE3+LCE3, 0);
    totS5 = totS4 = totS3 = totCE5 = totCE4 = totCE3 = 0;

    std::fill(memory, memory+100000, 0);
    unsigned long long* L5SL = new unsigned long long[LS5];
    unsigned long long* L4SL = new unsigned long long[LS4];
    unsigned long long* L3SL = new unsigned long long[LS3];
    unsigned long long* L5CEL = new unsigned long long[LCE5];
    unsigned long long* L4CEL = new unsigned long long[LCE4];
    unsigned long long* L3CEL = new unsigned long long[LCE3];

    for(int i = 0; i < times; ++i)
    {
        fgo_simulator::stone = 0;
        S5 = S4 = S3 = CE5 = CE4 = CE3 = 0;
        std::fill(L5SL, L5SL+LS5, 0);
        std::fill(L4SL, L4SL+LS4, 0);
        std::fill(L3SL, L3SL+LS3, 0);
        std::fill(L5CEL, L5CEL+LCE5, 0);
        std::fill(L4CEL, L4CEL+LCE4, 0);
        std::fill(L3CEL, L3CEL+LCE3, 0);

        int freeSummon = 0;
        while(L4SL[servent-1] < serventNP)
        {
            int roll = rand() % 100 + 1;
            if(roll >= 1 && roll < 1+S5PU)
            {
                ++S5;
                int Lroll = rand() % 100 + 1;
                if(Lroll <= 100*LS5PU/S5PU) 
                {
                    ++L5SL[rand() % LS5];
                }
            }
            else if(roll >= 1+S5PU && roll < 1+S5PU+S4PU)
            {
                ++S4;
                int Lroll = rand() % 100 + 1;
                if(Lroll <= 100*LS4PU/S4PU) 
                {
                    ++L4SL[rand() % LS4];
                }
            }
            else if(roll >= 1+S5PU+S4PU && roll < 1+S5PU+S4PU+S3PU)
            {
                ++S3;
                int Lroll = rand() % 100 + 1;
                if(Lroll <= 100*LS3PU/S3PU) 
                {
                    ++L3SL[rand() % LS3];
                }
            }
            else if(roll >= 1+S5PU+S4PU+S3PU && roll < 1+S5PU+S4PU+S3PU+CE5PU)
            {
                ++CE5;
                int Lroll = rand() % 100 + 1;
                if(Lroll <= 100*LCE5PU/CE5PU) 
                {
                    ++L5CEL[rand() % LCE5];
                }
            }
            else if(roll >= 1+S5PU+S4PU+S3PU+CE5PU && roll < 1+S5PU+S4PU+S3PU+CE5PU+CE4PU)
            {
                ++CE4;
                int Lroll = rand() % 100 + 1;
                if(Lroll <= 100*LCE4PU/CE4PU) 
                {
                    ++L4CEL[rand() % LCE4];
                }
            }
            else if(roll >= 1+S5PU+S4PU+S3PU+CE5PU+CE4PU && roll < 1+S5PU+S4PU+S3PU+CE5PU+CE4PU+CE3PU)
            {
                ++CE3;
                int Lroll = rand() % 100 + 1;
                if(Lroll <= 100*LCE3PU/CE3PU) 
                {
                    ++L3CEL[rand() % LCE3];
                }
            }
            if((++freeSummon %= 11) != 10) stone += 3;
        }
        totCE5 += CE5;
        totCE4 += CE4;
        totCE3 += CE3;
        totS5 += S5;
        totS4 += S4;
        totS3 += S3;
        for(int i = 0; i < LCE5; ++i) totLCE5[i] += L5CEL[i];
        for(int i = 0; i < LCE4; ++i) totLCE4[i] += L4CEL[i];
        for(int i = 0; i < LCE3; ++i) totLCE3[i] += L3CEL[i];
        for(int i = 0; i < LS5; ++i) totLS5[i] += L5SL[i];
        for(int i = 0; i < LS4; ++i) totLS4[i] += L4SL[i];
        for(int i = 0; i < LS3; ++i) totLS3[i] += L3SL[i];
        totStone += stone;
        ++memory[stone/3];
    }
}

void fgo_simulator::summonL3star(const int servent, const int serventNP)
{
    srand(time(NULL));
    totStone = 0;
    std::fill(totLS5, totLS5+LS5, 0);
    std::fill(totLS4, totLS4+LS4, 0);
    std::fill(totLS3, totLS3+LS3, 0);
    std::fill(totLCE5, totLCE5+LCE5, 0);
    std::fill(totLCE4, totLCE4+LCE4, 0);
    std::fill(totLCE3, totLCE3+LCE3, 0);
    totS5 = totS4 = totS3 = totCE5 = totCE4 = totCE3 = 0;

    std::fill(memory, memory+100000, 0);
    unsigned long long* L5SL = new unsigned long long[LS5];
    unsigned long long* L4SL = new unsigned long long[LS4];
    unsigned long long* L3SL = new unsigned long long[LS3];
    unsigned long long* L5CEL = new unsigned long long[LCE5];
    unsigned long long* L4CEL = new unsigned long long[LCE4];
    unsigned long long* L3CEL = new unsigned long long[LCE3];

    for(int i = 0; i < times; ++i)
    {
        fgo_simulator::stone = 0;
        S5 = S4 = S3 = CE5 = CE4 = CE3 = 0;
        std::fill(L5SL, L5SL+LS5, 0);
        std::fill(L4SL, L4SL+LS4, 0);
        std::fill(L3SL, L3SL+LS3, 0);
        std::fill(L5CEL, L5CEL+LCE5, 0);
        std::fill(L4CEL, L4CEL+LCE4, 0);
        std::fill(L3CEL, L3CEL+LCE3, 0);

        int freeSummon = 0;
        while(L3SL[servent-1] < serventNP)
        {
            int roll = rand() % 100 + 1;
            if(roll >= 1 && roll < 1+S5PU)
            {
                ++S5;
                int Lroll = rand() % 100 + 1;
                if(Lroll <= 100*LS5PU/S5PU) 
                {
                    ++L5SL[rand() % LS5];
                }
            }
            else if(roll >= 1+S5PU && roll < 1+S5PU+S4PU)
            {
                ++S4;
                int Lroll = rand() % 100 + 1;
                if(Lroll <= 100*LS4PU/S4PU) 
                {
                    ++L4SL[rand() % LS4];
                }
            }
            else if(roll >= 1+S5PU+S4PU && roll < 1+S5PU+S4PU+S3PU)
            {
                ++S3;
                int Lroll = rand() % 100 + 1;
                if(Lroll <= 100*LS3PU/S3PU) 
                {
                    ++L3SL[rand() % LS3];
                }
            }
            else if(roll >= 1+S5PU+S4PU+S3PU && roll < 1+S5PU+S4PU+S3PU+CE5PU)
            {
                ++CE5;
                int Lroll = rand() % 100 + 1;
                if(Lroll <= 100*LCE5PU/CE5PU) 
                {
                    ++L5CEL[rand() % LCE5];
                }
            }
            else if(roll >= 1+S5PU+S4PU+S3PU+CE5PU && roll < 1+S5PU+S4PU+S3PU+CE5PU+CE4PU)
            {
                ++CE4;
                int Lroll = rand() % 100 + 1;
                if(Lroll <= 100*LCE4PU/CE4PU) 
                {
                    ++L4CEL[rand() % LCE4];
                }
            }
            else if(roll >= 1+S5PU+S4PU+S3PU+CE5PU+CE4PU && roll < 1+S5PU+S4PU+S3PU+CE5PU+CE4PU+CE3PU)
            {
                ++CE3;
                int Lroll = rand() % 100 + 1;
                if(Lroll <= 100*LCE3PU/CE3PU) 
                {
                    ++L3CEL[rand() % LCE3];
                }
            }
            if((++freeSummon %= 11) != 10) stone += 3;
        }
        totCE5 += CE5;
        totCE4 += CE4;
        totCE3 += CE3;
        totS5 += S5;
        totS4 += S4;
        totS3 += S3;
        for(int i = 0; i < LCE5; ++i) totLCE5[i] += L5CEL[i];
        for(int i = 0; i < LCE4; ++i) totLCE4[i] += L4CEL[i];
        for(int i = 0; i < LCE3; ++i) totLCE3[i] += L3CEL[i];
        for(int i = 0; i < LS5; ++i) totLS5[i] += L5SL[i];
        for(int i = 0; i < LS4; ++i) totLS4[i] += L4SL[i];
        for(int i = 0; i < LS3; ++i) totLS3[i] += L3SL[i];
        totStone += stone;
        ++memory[stone/3];
    }
}

void fgo_simulator::summonL5star(const int servent, const int serventNP)
{
    srand(time(NULL));
    totStone = 0;
    std::fill(totLS5, totLS5+LS5, 0);
    std::fill(totLS4, totLS4+LS4, 0);
    std::fill(totLS3, totLS3+LS3, 0);
    std::fill(totLCE5, totLCE5+LCE5, 0);
    std::fill(totLCE4, totLCE4+LCE4, 0);
    std::fill(totLCE3, totLCE3+LCE3, 0);
    totS5 = totS4 = totS3 = totCE5 = totCE4 = totCE3 = 0;

    std::fill(memory, memory+100000, 0);
    unsigned long long* L5SL = new unsigned long long[LS5];
    unsigned long long* L4SL = new unsigned long long[LS4];
    unsigned long long* L3SL = new unsigned long long[LS3];
    unsigned long long* L5CEL = new unsigned long long[LCE5];
    unsigned long long* L4CEL = new unsigned long long[LCE4];
    unsigned long long* L3CEL = new unsigned long long[LCE3];

    for(int i = 0; i < times; ++i)
    {
        fgo_simulator::stone = 0;
        S5 = S4 = S3 = CE5 = CE4 = CE3 = 0;
        std::fill(L5SL, L5SL+LS5, 0);
        std::fill(L4SL, L4SL+LS4, 0);
        std::fill(L3SL, L3SL+LS3, 0);
        std::fill(L5CEL, L5CEL+LCE5, 0);
        std::fill(L4CEL, L4CEL+LCE4, 0);
        std::fill(L3CEL, L3CEL+LCE3, 0);

        int freeSummon = 0;
        while(L5SL[servent-1] < serventNP)
        {
            int roll = rand() % 100 + 1;
            if(roll >= 1 && roll < 1+S5PU)
            {
                ++S5;
                int Lroll = rand() % 100 + 1;
                if(Lroll <= 100*LS5PU/S5PU) 
                {
                    ++L5SL[rand() % LS5];
                }
            }
            else if(roll >= 1+S5PU && roll < 1+S5PU+S4PU)
            {
                ++S4;
                int Lroll = rand() % 100 + 1;
                if(Lroll <= 100*LS4PU/S4PU) 
                {
                    ++L4SL[rand() % LS4];
                }
            }
            else if(roll >= 1+S5PU+S4PU && roll < 1+S5PU+S4PU+S3PU)
            {
                ++S3;
                int Lroll = rand() % 100 + 1;
                if(Lroll <= 100*LS3PU/S3PU) 
                {
                    ++L3SL[rand() % LS3];
                }
            }
            else if(roll >= 1+S5PU+S4PU+S3PU && roll < 1+S5PU+S4PU+S3PU+CE5PU)
            {
                ++CE5;
                int Lroll = rand() % 100 + 1;
                if(Lroll <= 100*LCE5PU/CE5PU) 
                {
                    ++L5CEL[rand() % LCE5];
                }
            }
            else if(roll >= 1+S5PU+S4PU+S3PU+CE5PU && roll < 1+S5PU+S4PU+S3PU+CE5PU+CE4PU)
            {
                ++CE4;
                int Lroll = rand() % 100 + 1;
                if(Lroll <= 100*LCE4PU/CE4PU) 
                {
                    ++L4CEL[rand() % LCE4];
                }
            }
            else if(roll >= 1+S5PU+S4PU+S3PU+CE5PU+CE4PU && roll < 1+S5PU+S4PU+S3PU+CE5PU+CE4PU+CE3PU)
            {
                ++CE3;
                int Lroll = rand() % 100 + 1;
                if(Lroll <= 100*LCE3PU/CE3PU) 
                {
                    ++L3CEL[rand() % LCE3];
                }
            }
            if((++freeSummon %= 11) != 10) stone += 3;
        }
        totCE5 += CE5;
        totCE4 += CE4;
        totCE3 += CE3;
        totS5 += S5;
        totS4 += S4;
        totS3 += S3;
        for(int i = 0; i < LCE5; ++i) totLCE5[i] += L5CEL[i];
        for(int i = 0; i < LCE4; ++i) totLCE4[i] += L4CEL[i];
        for(int i = 0; i < LCE3; ++i) totLCE3[i] += L3CEL[i];
        for(int i = 0; i < LS5; ++i) totLS5[i] += L5SL[i];
        for(int i = 0; i < LS4; ++i) totLS4[i] += L4SL[i];
        for(int i = 0; i < LS3; ++i) totLS3[i] += L3SL[i];
        totStone += stone;
        ++memory[stone/3];
    }
}

void fgo_simulator::summon(unsigned long long stones)
{
    srand(time(NULL));
    totStone = 0;
    std::fill(totLS5, totLS5+LS5, 0);
    std::fill(totLS4, totLS4+LS4, 0);
    std::fill(totLS3, totLS3+LS3, 0);
    std::fill(totLCE5, totLCE5+LCE5, 0);
    std::fill(totLCE4, totLCE4+LCE4, 0);
    std::fill(totLCE3, totLCE3+LCE3, 0);
    totS5 = totS4 = totS3 = totCE5 = totCE4 = totCE3 = 0;

    unsigned long long* L5SL = new unsigned long long[LS5];
    unsigned long long* L4SL = new unsigned long long[LS4];
    unsigned long long* L3SL = new unsigned long long[LS3];
    unsigned long long* L5CEL = new unsigned long long[LCE5];
    unsigned long long* L4CEL = new unsigned long long[LCE4];
    unsigned long long* L3CEL = new unsigned long long[LCE3];

    unsigned long long S5, S4, S3, CE5, CE4, CE3;
    for(int i = 0; i < times; ++i)
    {
        int stone = stones;
        S5 = S4 = S3 = CE5 = CE4 = CE3 = 0;
        std::fill(L5SL, L5SL+LS5, 0);
        std::fill(L4SL, L4SL+LS4, 0);
        std::fill(L3SL, L3SL+LS3, 0);
        std::fill(L5CEL, L5CEL+LCE5, 0);
        std::fill(L4CEL, L4CEL+LCE4, 0);
        std::fill(L3CEL, L3CEL+LCE3, 0);

        int freeSummon = 0;
        while(stone >= 3)
        {
            int roll = rand() % 100 + 1;
            if(roll >= 1 && roll < 1+S5PU)
            {
                ++S5;
                int Lroll = rand() % 100 + 1;
                if(Lroll <= 100*LS5PU/S5PU) 
                {
                    ++L5SL[rand() % LS5];
                }
            }
            else if(roll >= 1+S5PU && roll < 1+S5PU+S4PU)
            {
                ++S4;
                int Lroll = rand() % 100 + 1;
                if(Lroll <= 100*LS4PU/S4PU) 
                {
                    ++L4SL[rand() % LS4];
                }
            }
            else if(roll >= 1+S5PU+S4PU && roll < 1+S5PU+S4PU+S3PU)
            {
                ++S3;
                int Lroll = rand() % 100 + 1;
                if(Lroll <= 100*LS3PU/S3PU) 
                {
                    ++L3SL[rand() % LS3];
                }
            }
            else if(roll >= 1+S5PU+S4PU+S3PU && roll < 1+S5PU+S4PU+S3PU+CE5PU)
            {
                ++CE5;
                int Lroll = rand() % 100 + 1;
                if(Lroll <= 100*LCE5PU/CE5PU) 
                {
                    ++L5CEL[rand() % LCE5];
                }
            }
            else if(roll >= 1+S5PU+S4PU+S3PU+CE5PU && roll < 1+S5PU+S4PU+S3PU+CE5PU+CE4PU)
            {
                ++CE4;
                int Lroll = rand() % 100 + 1;
                if(Lroll <= 100*LCE4PU/CE4PU) 
                {
                    ++L4CEL[rand() % LCE4];
                }
            }
            else if(roll >= 1+S5PU+S4PU+S3PU+CE5PU+CE4PU && roll < 1+S5PU+S4PU+S3PU+CE5PU+CE4PU+CE3PU)
            {
                ++CE3;
                int Lroll = rand() % 100 + 1;
                if(Lroll <= 100*LCE3PU/CE3PU) 
                {
                    ++L3CEL[rand() % LCE3];
                }
            }
            if((++freeSummon %= 11) != 10) stone -= 3;
        }
        totCE5 += CE5;
        totCE4 += CE4;
        totCE3 += CE3;
        totS5 += S5;
        totS4 += S4;
        totS3 += S3;

        for(int i = 0; i < LCE5; ++i) totLCE5[i] += L5CEL[i];
        for(int i = 0; i < LCE4; ++i) totLCE4[i] += L4CEL[i];
        for(int i = 0; i < LCE3; ++i) totLCE3[i] += L3CEL[i];
        for(int i = 0; i < LS5; ++i) totLS5[i] += L5SL[i];
        for(int i = 0; i < LS4; ++i) totLS4[i] += L4SL[i];
        for(int i = 0; i < LS3; ++i) totLS3[i] += L3SL[i];
        totStone += stones;
    }
}

void fgo_simulator::show()
{
    std::cout << "성정석 : " << double(totStone)/times << " 시행 : " << times << '\n';
    std::cout << "5성 서번트 : " << double(totS5)/times << '\n';
    std::cout << "4성 서번트 : " << double(totS4)/times << '\n';
    std::cout << "3성 서번트 : " << double(totS3)/times << '\n';
    std::cout << "5성 예장 : " << double(totCE5)/times << '\n';
    std::cout << "4성 예장 : " << double(totCE4)/times << '\n';
    std::cout << "3성 예장 : " << double(totCE3)/times << '\n';
    for(int i = 0; i < LS5; ++i) std::cout << "픽업 5성 서번트" << i+1 << " : " << double(totLS5[i])/times << '\n';
    for(int i = 0; i < LS4; ++i) std::cout << "픽업 4성 서번트" << i+1 << " : " << double(totLS4[i])/times << '\n';
    for(int i = 0; i < LS3; ++i) std::cout << "픽업 3성 서번트" << i+1 << " : " << double(totLS3[i])/times << '\n';
    for(int i = 0; i < LCE5; ++i) std::cout << "픽업 5성 예장" << i+1 << " : " << double(totLCE5[i])/times << '\n';
    for(int i = 0; i < LCE4; ++i) std::cout << "픽업 4성 예장" << i+1 << " : " << double(totLCE4[i])/times << '\n';
    for(int i = 0; i < LCE3; ++i) std::cout << "픽업 3성 예장" << i+1 << " : " << double(totLCE3[i])/times << '\n';
}
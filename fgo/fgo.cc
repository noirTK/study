#include "fgo.h"

void fgo_simulator::setPU(const int rank, const int target)
{
    if(rank == 5) LS5PU = (target == 1) ? 0.7 : 0.8;
    if(rank == 4) LS4PU = (target == 1) ? 1.5 : 2.4;
}

void fgo_simulator::C11summon(unsigned long long stones)
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

    ullp L5SL = new ull[LS5];
    ullp L4SL = new ull[LS4];
    ullp L3SL = new ull[LS3];
    ullp L5CEL = new ull[LCE5];
    ullp L4CEL = new ull[LCE4];
    ullp L3CEL = new ull[LCE3];

    ull S5, S4, S3, CE5, CE4, CE3;
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
        
        while(stone >= S11_NEED_STONE)
        {
            // 연차 하면 4성 이상의 서번트 혹은 예장이 1개 확정
            int goldRoll = rand() % int(S5PU+S4PU+CE5PU+CE4PU) + 1;
            if(goldRoll >= 1 && goldRoll < 1+S5PU)
            {
                ++S5;
                int Lroll = rand() % 100 + 1;
                if(Lroll <= 100*LS5PU/S5PU) 
                {
                    ++L5SL[rand() % LS5];
                }
            }
            else if(goldRoll >= 1+S5PU && goldRoll < 1+S5PU+S4PU)
            {
                ++S4;
                int Lroll = rand() % 100 + 1;
                if(Lroll <= 100*LS4PU/S4PU) 
                {
                    ++L4SL[rand() % LS4];
                }
            }
            else if(goldRoll >= 1+S5PU+S4PU && goldRoll < 1+S5PU+S4PU+CE5PU)
            {
                ++CE5;
                int Lroll = rand() % 100 + 1;
                if(Lroll <= 100*LCE5PU/CE5PU) 
                {
                    ++L5CEL[rand() % LCE5];
                }
            }
            else if(goldRoll >= 1+S5PU+S4PU+CE5PU && goldRoll < S5PU+S4PU+CE5PU+CE4PU)
            {
                ++CE4;
                int Lroll = rand() % 100 + 1;
                if(Lroll <= 100*LCE4PU/CE4PU) 
                {
                    ++L4CEL[rand() % LCE4];
                }
            }

            // 연차 하면 3성 이상의 서번트가 1개 확정
            int ServentRoll = rand() % int(S5PU+S4PU+S3PU) + 1;
            if(ServentRoll >= 1 && ServentRoll < 1+S5PU)
            {
                ++S5;
                int Lroll = rand() % 100 + 1;
                if(Lroll <= 100*LS5PU/S5PU) 
                {
                ++L5SL[rand() % LS5];
                }
            }
            else if(ServentRoll >= 1+S5PU && ServentRoll < 1+S5PU+S4PU)
            {
                ++S4;
                int Lroll = rand() % 100 + 1;
                if(Lroll <= 100*LS4PU/S4PU) 
                {
                    ++L4SL[rand() % LS4];
                }
            }
            else if(ServentRoll >= 1+S5PU+S4PU && ServentRoll < 1+S5PU+S4PU+S3PU)
            {
                ++S3;
                int Lroll = rand() % 100 + 1;
                if(Lroll <= 100*LS3PU/S3PU) 
                {
                    ++L3SL[rand() % LS3];
                }
            }

            // 나머지 9개는 평범한 단차
            for(int i = 1; i <= 9; ++i)
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
            }
            stone -= S11_NEED_STONE;
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

void fgo_simulator::C11summonPickServent(const int rank, const int choice, const int NP)
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
    ullp L5SL = new ull[LS5];
    ullp L4SL = new ull[LS4];
    ullp L3SL = new ull[LS3];
    ullp L5CEL = new ull[LCE5];
    ullp L4CEL = new ull[LCE4];
    ullp L3CEL = new ull[LCE3];

    unsigned long long S5, S4, S3, CE5, CE4, CE3;
    for(int i = 0; i < times; ++i)
    {
        long long stone = 0;
        S5 = S4 = S3 = CE5 = CE4 = CE3 = 0;
        std::fill(L5SL, L5SL+LS5, 0);
        std::fill(L4SL, L4SL+LS4, 0);
        std::fill(L3SL, L3SL+LS3, 0);
        std::fill(L5CEL, L5CEL+LCE5, 0);
        std::fill(L4CEL, L4CEL+LCE4, 0);
        std::fill(L3CEL, L3CEL+LCE3, 0);

        // 여기서 포인터로 스위칭
        const unsigned long long * pickS;
        if(rank == 3) pickS = L3SL;
        else if(rank == 4) pickS = L4SL;
        else if(rank == 5) pickS = L5SL;
        // 여기서 포인터로 스위칭

        while(pickS[choice-1] < NP)
        {
            // 연차 하면 4성 이상의 개념예장 혹은 서번트가 1개 확정
            int goldRoll = rand() % int(S5PU+S4PU+CE5PU+CE4PU) + 1;
            if(goldRoll >= 1 && goldRoll < 1+S5PU)
            {
                ++S5;
                int Lroll = rand() % 100 + 1;
                if(Lroll <= 100*LS5PU/S5PU) 
                {
                    ++L5SL[rand() % LS5];
                }
            }
            else if(goldRoll >= 1+S5PU && goldRoll < 1+S5PU+S4PU)
            {
                ++S4;
                int Lroll = rand() % 100 + 1;
                if(Lroll <= 100*LS4PU/S4PU) 
                {
                    ++L4SL[rand() % LS4];
                }
            }
            else if(goldRoll >= 1+S5PU+S4PU && goldRoll < 1+S5PU+S4PU+CE5PU)
            {
                ++CE5;
                int Lroll = rand() % 100 + 1;
                if(Lroll <= 100*LCE5PU/CE5PU) 
                {
                    ++L5CEL[rand() % LCE5];
                }
            }
            else if(goldRoll >= 1+S5PU+S4PU+CE5PU && goldRoll < S5PU+S4PU+CE5PU+CE4PU)
            {
                ++CE4;
                int Lroll = rand() % 100 + 1;
                if(Lroll <= 100*LCE4PU/CE4PU) 
                {
                    ++L4CEL[rand() % LCE4];
                }
            }
            // 연차 하면 3성 이상의 서번트가 1개 확정
            int ServentRoll = rand() % int(S5PU+S4PU+S3PU) + 1;
            if(ServentRoll >= 1 && ServentRoll < 1+S5PU)
            {
                ++S5;
                int Lroll = rand() % 100 + 1;
                if(Lroll <= 100*LS5PU/S5PU) 
                {
                    ++L5SL[rand() % LS5];
                }
            }
            else if(ServentRoll >= 1+S5PU && ServentRoll < 1+S5PU+S4PU)
            {
                ++S4;
                int Lroll = rand() % 100 + 1;
                if(Lroll <= 100*LS4PU/S4PU) 
                {
                    ++L4SL[rand() % LS4];
                }
            }
            else if(ServentRoll >= 1+S5PU+S4PU && ServentRoll < 1+S5PU+S4PU+S3PU)
            {
                ++S3;
                int Lroll = rand() % 100 + 1;
                if(Lroll <= 100*LS3PU/S3PU) 
                {
                    ++L3SL[rand() % LS3];
                }
            }
            // 나머지는 평범한 단차
            for(int i = 1; i <= 9; ++i)
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
            }
            stone += S11_NEED_STONE;
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
        ++memory[stone/S11_NEED_STONE];
    }
}

void fgo_simulator::C11showLuck(const int n) const
{
    ull ans = 0;
    for(int i = 1; i <= n/S11_NEED_STONE; ++i)
    {
        ans += memory[i];
    }
    std::cout.precision(2);
    std::cout << n << "개의 성정석으로, 성공할 확률은" << double(ans)/times*100 << "% 입니다." << '\n';
}

void fgo_simulator::C11showPercent() const
{
    for(int percent = 10; percent < 100; percent+=10)
    {
        ull ans = 0;
        int i;
        for(i = 1; i < 100000; ++i)
        {
            if(double(ans)/times > double(percent)/100) break;
            ans += memory[i];
        }
        std::cout << percent << "% 확률일 때 필요한 성정석 개수는 " << i*S11_NEED_STONE << "개입니다." << '\n';
    }
    for(int percent = 91; percent < 100; ++percent)
    {
        ull ans = 0;
        int i;
        for(i = 1; i < 100000; ++i)
        {
            if(double(ans)/times > double(percent)/100) break;
            ans += memory[i];
        }
        std::cout << percent << "% 확률일 때 필요한 성정석 개수는 " << i*S11_NEED_STONE << "개입니다." << '\n';
    }
}

void fgo_simulator::showLuck(const int n) const
{
    ull ans = 0;
    for(int i = 1; i <= n/NEED_STONE; ++i)
    {
        ans += memory[i];
    }
    std::cout.precision(2);
    std::cout << n << "개의 성정석으로, 성공할 확률은" << double(ans)/times*100 << "% 입니다." << '\n';
}

void fgo_simulator::showPercent() const
{
    for(int percent = 10; percent < 100; percent+=10)
    {
        ull ans = 0;
        int i;
        for(i = 1; i < 100000; ++i)
        {
            if(double(ans)/times > double(percent)/100) break;
            ans += memory[i];
        }
        std::cout << percent << "% 확률일 때 필요한 성정석 개수는 " << i*NEED_STONE << "개입니다." << '\n';
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
        std::cout << percent << "% 확률일 때 필요한 성정석 개수는 " << i*NEED_STONE << "개입니다." << '\n';
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

    ullp L5SL = new ull[LS5];
    ullp L4SL = new ull[LS4];
    ullp L3SL = new ull[LS3];
    ullp L5CEL = new ull[LCE5];
    ullp L4CEL = new ull[LCE4];
    ullp L3CEL = new ull[LCE3];

    ull S5, S4, S3, CE5, CE4, CE3;
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
        while(stone >= NEED_STONE)
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
            // 10번 단차하면 1회 공짜로 돌릴 수 있는 것.
            if((++freeSummon %= 11) != 10) stone -= NEED_STONE;
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

void fgo_simulator::summonPickServent(const int rank, const int choice, const int NP)
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
    ullp L5SL = new ull[LS5];
    ullp L4SL = new ull[LS4];
    ullp L3SL = new ull[LS3];
    ullp L5CEL = new ull[LCE5];
    ullp L4CEL = new ull[LCE4];
    ullp L3CEL = new ull[LCE3];

    ull S5, S4, S3, CE5, CE4, CE3;
    for(int i = 0; i < times; ++i)
    {
        long long stone = 0;
        S5 = S4 = S3 = CE5 = CE4 = CE3 = 0;
        std::fill(L5SL, L5SL+LS5, 0);
        std::fill(L4SL, L4SL+LS4, 0);
        std::fill(L3SL, L3SL+LS3, 0);
        std::fill(L5CEL, L5CEL+LCE5, 0);
        std::fill(L4CEL, L4CEL+LCE4, 0);
        std::fill(L3CEL, L3CEL+LCE3, 0);

        int freeSummon = 0;
        
        // 스위치 포인터
        const unsigned long long * pickS;
        if(rank == 3) pickS = L3SL;
        else if(rank == 4) pickS = L4SL;
        else if(rank == 5) pickS = L5SL;
        // 스위치 포인터

        while(pickS[choice-1] < NP)
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
        ++memory[stone/NEED_STONE];
    }
}

void fgo_simulator::show() const
{
    std::cout.precision(2);
    std::cout << "성정석 : " << totStone/times << " 테스트 케이스 : " << times << '\n';
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
/*
    Since : 2020. 07. 20.
    PROJECT. FGO PICKUP SIMULATOR
    FGO 가차 데이터를 분석하기 위해 만든 헤더파일.

    Class fgo_simulator

    S11_NEED_STONE : 1연차시 필요한 성정석 개수
    NEED_STONE : 1단차시 필요한 성정석 개수

    times : 테스트 케이스 개수
    totStone : 테스트 케이스 전체에서 특정 조건을 위해 필요한 성정석 개수
    totS5, totS4, totS3 : 테스트 케이스 전체에서 툭정 조건을 위해 필요한 서번트 개수
    totCE5, totCE4, totCE3 : 테스트 케이스 전체에서 툭정 조건을 위해 필요한 개념예장 개수
    totLS5, totLS4, totLS3 : 테스트 케이스 전체에서 툭정 조건을 위해 필요한 픽업 확률 업 서번트를 배열을 가리키는 포인터
    totCE5, totCE4, totCE3 : 테스트 케이스 전체에서 툭정 조건을 위해 필요한 픽업 확률 업 개념예장 배열을 가리키는 포인터
    memory : n번째 배열, n = 특정 테스트 케이스에서 특정 조건을 위해 필요한 n*NEED_STONE || n*S11_NEED_STONE 개의 성정석 개수
    
    LS5 : 5성 서번트 확률업 대상 서번트 개수
    LS4 : 4성 서번트 확률업 대상 서번트 개수
    LS3 : 3성 서번트 확률업 대상 서번트 개수
    LCE5 : 5성 예장 확률업 대상 예장 개수
    LCE4 : 4성 예장 확률업 대상 예장 개수
    LCE3 : 3성 예장 확률업 대상 예장 개수

    S5PU : 전체에서 5성 서번트를 픽업할 확률 (소수점2, %단위)
    S4PU : 전체에서 4성 서번트를 픽업할 확률 (소수점2, %단위)
    S3PU : 전체에서 3성 서번트를 픽업할 확률 (소수점2, %단위)
    LS5PU : 전체에서 픽업 확률 업 5성 서번트를 픽업할 확률 (소수점2, %단위)
    LS4PU : 전체에서 픽업 확률 업 4성 서번트를 픽업할 확률 (소수점2, %단위)
    LS3PU : 전체에서 픽업 확률 업 3성 서번트를 픽업할 확률 (소수점2, %단위)
    CE5PU : 전체에서 5성 예장을 픽업할 확률 (소수점2, %단위)
    CE4PU : 전체에서 4성 예장을 픽업할 확률 (소수점2, %단위)
    CE3PU : 전체에서 3성 예장을 픽업할 확률 (소수점2, %단위)
    LCE5PU : 전체에서 픽업 확률 업 5성 예장을 픽업할 확률 (소수점2, %단위)
    LCE4PU : 전체에서 픽업 확률 업 4성 예장을 픽업할 확률 (소수점2, %단위)
    LCE3PU : 전체에서 픽업 확률 업 3성 예장을 픽업할 확률 (소수점2, %단위)

    void C11summon(unsigned long long stones) : stones 개의 성정석을 돌렸을 때의 연차시뮬
    void C11summonPickServent(const int rank, const int choice, const int NP) : rank = 3성, 4성, 5성 / choice = 확률업 대상 서번트 LS5, LS4, LS3개 중 하나 (choice = 1 ~ LS5,LS4,LS3) / NP : 뽑을 서번트 개수(보1 ~ 보5) 연차 시뮬
    void C11showLuck(const int n) const; n개의 성정석을 넣었을 떄 C11summonPickServent의 확률을 확인할 수 있다. (C11summonPickServent 호출 후 사용)
    void C11showPercent() const; C11summonPickServent를 만족하는 10~99% 각 확률당 필요한 성정석 개수를 확인할 수 있다. (C11summonPickServent 호출 후 사용)
    
    void summon(unsigned long long stones); : stones 개의 성정석을 돌렸을 때의 단차확률
    void summonPickServent(const int rank, const int choice, const int NP);  rank = 3성, 4성, 5성 / choice = 확률업 대상 서번트 LS5, LS4, LS3개 중 하나 (choice = 1 ~ LS5,LS4,LS3) / NP : 뽑을 서번트 개수(보1 ~ 보5) 단차 시뮬
    void showLuck(const int n) const; n개의 성정석을 넣었을 떄 summonPickServent의 확률을 확인할 수 있다. (summonPickServent 호출 후 사용)
    void showPercent() const; summonPickServent를  만족하는 10~99% 각 확률당 필요한 성정석 개수를 확인할 수 있다. (summonPickServent 호출 후 사용)

    void show() const; C11summon/C11summonPickServent/summon/summonPickServent의 평균 결과를 보여줌. tot에서 times 나눈 것.
*/

#ifndef _fgo_simulator_H_
#define _fgo_simulator_H_

const int S11_NEED_STONE = 30;
const int NEED_STONE = 3;

typedef unsigned long long ull;
typedef unsigned long long * ullp;

#include <ctime>
#include <iostream>

class fgo_simulator
{
    const ull times;
    ull totStone;
    unsigned int totS5, totS4, totS3, totCE5, totCE4, totCE3;
    unsigned int LS5, LS4, LS3, LCE5, LCE4, LCE3;
    ullp totLS5, totLS4, totLS3, totLCE5, totLCE4, totLCE3;
    ullp memory;

    const double S5PU = 1;
    const double S4PU = 3;
    const double S3PU = 40;
    const double CE5PU = 4;
    const double CE4PU = 12;
    const double CE3PU = 40;

    const double LS5PU = 0.8;
    const double LS4PU = 1.5;
    const double LS3PU = 4;
    const double LCE5PU = 3.6;
    const double LCE4PU = 10;
    const double LCE3PU = 36;

    public:
    fgo_simulator(unsigned long long times = 1000000, unsigned int LS5 = 1, unsigned int LS4 = 1, unsigned int LS3 = 1, unsigned int LCE5 = 1, unsigned int LCE4 = 1, unsigned int LCE3 = 1) : times(times), LS5(LS5), LS4(LS4), LS3(LS3), LCE5(LCE5), LCE4(LCE4), LCE3(LCE3)
    {
        totLS5 = new unsigned long long[LS5];
        totLS4 = new unsigned long long[LS4];
        totLS3 = new unsigned long long[LS3];
        totLCE5 = new unsigned long long[LCE5];
        totLCE4 = new unsigned long long[LCE4];
        totLCE3 = new unsigned long long[LCE3];
        memory = new unsigned long long[100000];
    };
    ~fgo_simulator()
    {
        delete [] totLS4;
        delete [] totLS3;
        delete [] totLCE5;
        delete [] totLCE4;
        delete [] totLCE3;
        delete [] memory;
    }
    
    void C11summon(unsigned long long stones = S11_NEED_STONE);
    void C11summonPickServent(const int rank = 5, const int choice = 1, const int NP = 1);
    void C11showLuck(const int n = S11_NEED_STONE) const;
    void C11showPercent() const;

    void summon(unsigned long long stones = NEED_STONE);
    void summonPickServent(const int rank = 5, const int choice = 1, const int NP = 1);
    void showLuck(const int n = NEED_STONE) const;
    void showPercent() const;

    void show() const;
};

#endif
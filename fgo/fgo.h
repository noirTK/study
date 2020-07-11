#ifndef _fgo_simulator_H_
#define _fgo_simulator_H_

class fgo_simulator
{
    private:
    unsigned long long times;
    unsigned long long stone, totStone;
    unsigned int totS5, totS4, totS3, totCE5, totCE4, totCE3;
    unsigned int LS5, LS4, LS3, LCE5, LCE4, LCE3;
    unsigned int S5, S4, S3, CE5, CE4, CE3;

    unsigned long long * totLS5;
    unsigned long long * totLS4;
    unsigned long long * totLS3;
    unsigned long long * totLCE5;
    unsigned long long * totLCE4;
    unsigned long long * totLCE3;
    unsigned long long * memory;

    double S5PU = 1;
    double LS5PU = 0.8;
    double S4PU = 3;
    double LS4PU = 1.5;
    double S3PU = 40;
    double LS3PU = 4;
    double CE5PU = 4;
    double LCE5PU = 3.6;
    double CE4PU = 12;
    double LCE4PU = 10;
    double CE3PU = 40;
    double LCE3PU = 36;

    public:
    fgo_simulator(unsigned long long times = 1000000, unsigned int LS5 = 1, unsigned int LS4 = 1, unsigned int LS3 = 1, unsigned int LCE5 = 1, unsigned int LCE4 = 1, unsigned int LCE3 = 1, unsigned int S5 = 1, unsigned int S4 = 1, unsigned int S3 = 1, unsigned int CE5 = 1, unsigned int CE4 = 1, unsigned int CE3 = 1) : times(times), LS5(LS5), LS4(LS4), LS3(LS3), LCE5(LCE5), LCE4(LCE4), LCE3(LCE3)
    {
        totLS5 = new unsigned long long[S5];
        totLS4 = new unsigned long long[S4];
        totLS3 = new unsigned long long[S3];
        totLCE5 = new unsigned long long[CE5];
        totLCE4 = new unsigned long long[CE4];
        totLCE3 = new unsigned long long[CE3];
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
    void summon(unsigned long long stones);
    void C11summon(unsigned long long stones);
    void summonL5star(const int servent, const int serventNP);
    void summonL4star(const int servent, const int serventNP);
    void summonL3star(const int servent, const int serventNP);
    void showLuck(const int n);
    void showPercent();
    void show();
};

#endif
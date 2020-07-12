#include "fgo.h"

using namespace std;
int main()
{
    fgo_simulator s(100000, 1, 1, 1);

    cout << "1. 단차로 성정석 300개 사용" << '\n';
    s.summon(300);
    s.show();
    
    cout << '\n';

    cout << "2. 단차로 확률업 5성 서번트 1개중 1개를 보구 1업 할 때 필요한 성정석 개수 테스트" << '\n';
    s.summonPickServent(true, 5, 1, 1);
    s.showLuck(300);
    s.showPercent();

    cout << '\n';

    cout << "3. 연차로 성정석 300개 사용" << '\n';
    s.C11summon(300);
    s.show();

    cout << '\n';

    cout << "4. 연차로 확률업 5성 서번트 1개를 보구 1업 할 때 필요한 성정석 개수 테스트" << '\n';
    s.C11summonPickServent(true, 5, 1, 1);
    s.C11showLuck(300);
    s.C11showPercent();

    return 0;
}

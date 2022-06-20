//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// REQUIRES: long_tests

// <random>

// template<class IntType = int>
// class binomial_distribution

// template<class _URNG> result_type operator()(_URNG& g);

#include <random>
#include <numeric>
#include <vector>
#include <cassert>
#include <sstream>

#include "test_macros.h"

template <class T>
inline
T
sqr(T x)
{
    return x * x;
}

void
test1()
{
    typedef std::binomial_distribution<> D;
    typedef std::mt19937_64 G;
    G g;
    D d(5, .75);
    const int N = 1000000;
    std::vector<D::result_type> u;
    for (int i = 0; i < N; ++i)
    {
        D::result_type v = d(g);
        assert(d.min() <= v && v <= d.max());
        u.push_back(v);
    }
    double mean = std::accumulate(u.begin(), u.end(),
                                          double(0)) / u.size();
    double var = 0;
    double skew = 0;
    double kurtosis = 0;
    for (unsigned i = 0; i < u.size(); ++i)
    {
        double dbl = (u[i] - mean);
        double d2 = sqr(dbl);
        var += d2;
        skew += dbl * d2;
        kurtosis += d2 * d2;
    }
    var /= u.size();
    double dev = std::sqrt(var);
    skew /= u.size() * dev * var;
    kurtosis /= u.size() * var * var;
    kurtosis -= 3;
    double x_mean = d.t() * d.p();
    double x_var = x_mean*(1-d.p());
    double x_skew = (1-2*d.p()) / std::sqrt(x_var);
    double x_kurtosis = (1-6*d.p()*(1-d.p())) / x_var;
    assert(std::abs((mean - x_mean) / x_mean) < 0.01);
    assert(std::abs((var - x_var) / x_var) < 0.01);
    assert(std::abs((skew - x_skew) / x_skew) < 0.01);
    assert(std::abs((kurtosis - x_kurtosis) / x_kurtosis) < 0.04);
}

void
test2()
{
    typedef std::binomial_distribution<> D;
    typedef std::mt19937 G;
    G g;
    D d(30, .03125);
    const int N = 100000;
    std::vector<D::result_type> u;
    for (int i = 0; i < N; ++i)
    {
        D::result_type v = d(g);
        assert(d.min() <= v && v <= d.max());
        u.push_back(v);
    }
    double mean = std::accumulate(u.begin(), u.end(),
                                          double(0)) / u.size();
    double var = 0;
    double skew = 0;
    double kurtosis = 0;
    for (unsigned i = 0; i < u.size(); ++i)
    {
        double dbl = (u[i] - mean);
        double d2 = sqr(dbl);
        var += d2;
        skew += dbl * d2;
        kurtosis += d2 * d2;
    }
    var /= u.size();
    double dev = std::sqrt(var);
    skew /= u.size() * dev * var;
    kurtosis /= u.size() * var * var;
    kurtosis -= 3;
    double x_mean = d.t() * d.p();
    double x_var = x_mean*(1-d.p());
    double x_skew = (1-2*d.p()) / std::sqrt(x_var);
    double x_kurtosis = (1-6*d.p()*(1-d.p())) / x_var;
    assert(std::abs((mean - x_mean) / x_mean) < 0.01);
    assert(std::abs((var - x_var) / x_var) < 0.01);
    assert(std::abs((skew - x_skew) / x_skew) < 0.01);
    assert(std::abs((kurtosis - x_kurtosis) / x_kurtosis) < 0.01);
}

void
test3()
{
    typedef std::binomial_distribution<> D;
    typedef std::mt19937 G;
    G g;
    D d(40, .25);
    const int N = 100000;
    std::vector<D::result_type> u;
    for (int i = 0; i < N; ++i)
    {
        D::result_type v = d(g);
        assert(d.min() <= v && v <= d.max());
        u.push_back(v);
    }
    double mean = std::accumulate(u.begin(), u.end(),
                                          double(0)) / u.size();
    double var = 0;
    double skew = 0;
    double kurtosis = 0;
    for (unsigned i = 0; i < u.size(); ++i)
    {
        double dbl = (u[i] - mean);
        double d2 = sqr(dbl);
        var += d2;
        skew += dbl * d2;
        kurtosis += d2 * d2;
    }
    var /= u.size();
    double dev = std::sqrt(var);
    skew /= u.size() * dev * var;
    kurtosis /= u.size() * var * var;
    kurtosis -= 3;
    double x_mean = d.t() * d.p();
    double x_var = x_mean*(1-d.p());
    double x_skew = (1-2*d.p()) / std::sqrt(x_var);
    double x_kurtosis = (1-6*d.p()*(1-d.p())) / x_var;
    assert(std::abs((mean - x_mean) / x_mean) < 0.01);
    assert(std::abs((var - x_var) / x_var) < 0.01);
    assert(std::abs((skew - x_skew) / x_skew) < 0.03);
    assert(std::abs((kurtosis - x_kurtosis) / x_kurtosis) < 0.3);
}

void
test4()
{
    typedef std::binomial_distribution<> D;
    typedef std::mt19937 G;
    G g;
    D d(40, 0);
    const int N = 100000;
    std::vector<D::result_type> u;
    for (int i = 0; i < N; ++i)
    {
        D::result_type v = d(g);
        assert(d.min() <= v && v <= d.max());
        u.push_back(v);
    }
    double mean = std::accumulate(u.begin(), u.end(),
                                          double(0)) / u.size();
    double var = 0;
    double skew = 0;
    double kurtosis = 0;
    for (unsigned i = 0; i < u.size(); ++i)
    {
        double dbl = (u[i] - mean);
        double d2 = sqr(dbl);
        var += d2;
        skew += dbl * d2;
        kurtosis += d2 * d2;
    }
    var /= u.size();
    //double dev = std::sqrt(var);
    // In this case:
    //   skew     computes to 0./0. == nan
    //   kurtosis computes to 0./0. == nan
    //   x_skew     == inf
    //   x_kurtosis == inf
    //   These tests are commented out because UBSan warns about division by 0
//    skew /= u.size() * dev * var;
//    kurtosis /= u.size() * var * var;
//    kurtosis -= 3;
    double x_mean = d.t() * d.p();
    double x_var = x_mean*(1-d.p());
//    double x_skew = (1-2*d.p()) / std::sqrt(x_var);
//    double x_kurtosis = (1-6*d.p()*(1-d.p())) / x_var;
    assert(mean == x_mean);
    assert(var == x_var);
//    assert(skew == x_skew);
//    assert(kurtosis == x_kurtosis);
}

void
test5()
{
    typedef std::binomial_distribution<> D;
    typedef std::mt19937 G;
    G g;
    D d(40, 1);
    const int N = 100000;
    std::vector<D::result_type> u;
    for (int i = 0; i < N; ++i)
    {
        D::result_type v = d(g);
        assert(d.min() <= v && v <= d.max());
        u.push_back(v);
    }
    double mean = std::accumulate(u.begin(), u.end(),
                                          double(0)) / u.size();
    double var = 0;
    double skew = 0;
    double kurtosis = 0;
    for (unsigned i = 0; i < u.size(); ++i)
    {
        double dbl = (u[i] - mean);
        double d2 = sqr(dbl);
        var += d2;
        skew += dbl * d2;
        kurtosis += d2 * d2;
    }
    var /= u.size();
//    double dev = std::sqrt(var);
    // In this case:
    //   skew     computes to 0./0. == nan
    //   kurtosis computes to 0./0. == nan
    //   x_skew     == -inf
    //   x_kurtosis == inf
    //   These tests are commented out because UBSan warns about division by 0
//    skew /= u.size() * dev * var;
//    kurtosis /= u.size() * var * var;
//    kurtosis -= 3;
    double x_mean = d.t() * d.p();
    double x_var = x_mean*(1-d.p());
//    double x_skew = (1-2*d.p()) / std::sqrt(x_var);
//    double x_kurtosis = (1-6*d.p()*(1-d.p())) / x_var;
    assert(mean == x_mean);
    assert(var == x_var);
//    assert(skew == x_skew);
//    assert(kurtosis == x_kurtosis);
}

void
test6()
{
    typedef std::binomial_distribution<> D;
    typedef std::mt19937 G;
    G g;
    D d(400, 0.5);
    const int N = 100000;
    std::vector<D::result_type> u;
    for (int i = 0; i < N; ++i)
    {
        D::result_type v = d(g);
        assert(d.min() <= v && v <= d.max());
        u.push_back(v);
    }
    double mean = std::accumulate(u.begin(), u.end(),
                                          double(0)) / u.size();
    double var = 0;
    double skew = 0;
    double kurtosis = 0;
    for (unsigned i = 0; i < u.size(); ++i)
    {
        double dbl = (u[i] - mean);
        double d2 = sqr(dbl);
        var += d2;
        skew += dbl * d2;
        kurtosis += d2 * d2;
    }
    var /= u.size();
    double dev = std::sqrt(var);
    skew /= u.size() * dev * var;
    kurtosis /= u.size() * var * var;
    kurtosis -= 3;
    double x_mean = d.t() * d.p();
    double x_var = x_mean*(1-d.p());
    double x_skew = (1-2*d.p()) / std::sqrt(x_var);
    double x_kurtosis = (1-6*d.p()*(1-d.p())) / x_var;
    assert(std::abs((mean - x_mean) / x_mean) < 0.01);
    assert(std::abs((var - x_var) / x_var) < 0.01);
    assert(std::abs(skew - x_skew) < 0.01);
    assert(std::abs(kurtosis - x_kurtosis) < 0.01);
}

void
test7()
{
    typedef std::binomial_distribution<> D;
    typedef std::mt19937 G;
    G g;
    D d(1, 0.5);
    const int N = 100000;
    std::vector<D::result_type> u;
    for (int i = 0; i < N; ++i)
    {
        D::result_type v = d(g);
        assert(d.min() <= v && v <= d.max());
        u.push_back(v);
    }
    double mean = std::accumulate(u.begin(), u.end(),
                                          double(0)) / u.size();
    double var = 0;
    double skew = 0;
    double kurtosis = 0;
    for (unsigned i = 0; i < u.size(); ++i)
    {
        double dbl = (u[i] - mean);
        double d2 = sqr(dbl);
        var += d2;
        skew += dbl * d2;
        kurtosis += d2 * d2;
    }
    var /= u.size();
    double dev = std::sqrt(var);
    skew /= u.size() * dev * var;
    kurtosis /= u.size() * var * var;
    kurtosis -= 3;
    double x_mean = d.t() * d.p();
    double x_var = x_mean*(1-d.p());
    double x_skew = (1-2*d.p()) / std::sqrt(x_var);
    double x_kurtosis = (1-6*d.p()*(1-d.p())) / x_var;
    assert(std::abs((mean - x_mean) / x_mean) < 0.01);
    assert(std::abs((var - x_var) / x_var) < 0.01);
    assert(std::abs(skew - x_skew) < 0.01);
    assert(std::abs((kurtosis - x_kurtosis) / x_kurtosis) < 0.01);
}

void
test8()
{
    const int N = 100000;
    std::mt19937 gen1;
    std::mt19937 gen2;

    std::binomial_distribution<>         dist1(5, 0.1);
    std::binomial_distribution<unsigned> dist2(5, 0.1);

    for(int i = 0; i < N; ++i) {
        int r1 = dist1(gen1);
        unsigned r2 = dist2(gen2);
        assert(r1 >= 0);
        assert(static_cast<unsigned>(r1) == r2);
    }
}

void
test9()
{
    typedef std::binomial_distribution<> D;
    typedef std::mt19937 G;
    G g;
    D d(0, 0.005);
    const int N = 100000;
    std::vector<D::result_type> u;
    for (int i = 0; i < N; ++i)
    {
        D::result_type v = d(g);
        assert(d.min() <= v && v <= d.max());
        u.push_back(v);
    }
    double mean = std::accumulate(u.begin(), u.end(),
                                          double(0)) / u.size();
    double var = 0;
    double skew = 0;
    double kurtosis = 0;
    for (unsigned i = 0; i < u.size(); ++i)
    {
        double dbl = (u[i] - mean);
        double d2 = sqr(dbl);
        var += d2;
        skew += dbl * d2;
        kurtosis += d2 * d2;
    }
    var /= u.size();
//    double dev = std::sqrt(var);
    // In this case:
    //   skew     computes to 0./0. == nan
    //   kurtosis computes to 0./0. == nan
    //   x_skew     == inf
    //   x_kurtosis == inf
    //   These tests are commented out because UBSan warns about division by 0
//    skew /= u.size() * dev * var;
//    kurtosis /= u.size() * var * var;
//    kurtosis -= 3;
    double x_mean = d.t() * d.p();
    double x_var = x_mean*(1-d.p());
//    double x_skew = (1-2*d.p()) / std::sqrt(x_var);
//    double x_kurtosis = (1-6*d.p()*(1-d.p())) / x_var;
    assert(mean == x_mean);
    assert(var == x_var);
//    assert(skew == x_skew);
//    assert(kurtosis == x_kurtosis);
}

void
test10()
{
    typedef std::binomial_distribution<> D;
    typedef std::mt19937 G;
    G g;
    D d(0, 0);
    const int N = 100000;
    std::vector<D::result_type> u;
    for (int i = 0; i < N; ++i)
    {
        D::result_type v = d(g);
        assert(d.min() <= v && v <= d.max());
        u.push_back(v);
    }
    double mean = std::accumulate(u.begin(), u.end(),
                                          double(0)) / u.size();
    double var = 0;
    double skew = 0;
    double kurtosis = 0;
    for (unsigned i = 0; i < u.size(); ++i)
    {
        double dbl = (u[i] - mean);
        double d2 = sqr(dbl);
        var += d2;
        skew += dbl * d2;
        kurtosis += d2 * d2;
    }
    var /= u.size();
//    double dev = std::sqrt(var);
    // In this case:
    //   skew     computes to 0./0. == nan
    //   kurtosis computes to 0./0. == nan
    //   x_skew     == inf
    //   x_kurtosis == inf
    //   These tests are commented out because UBSan warns about division by 0
//    skew /= u.size() * dev * var;
//    kurtosis /= u.size() * var * var;
//    kurtosis -= 3;
    double x_mean = d.t() * d.p();
    double x_var = x_mean*(1-d.p());
//    double x_skew = (1-2*d.p()) / std::sqrt(x_var);
//    double x_kurtosis = (1-6*d.p()*(1-d.p())) / x_var;
    assert(mean == x_mean);
    assert(var == x_var);
//    assert(skew == x_skew);
//    assert(kurtosis == x_kurtosis);
}

void
test11()
{
    typedef std::binomial_distribution<> D;
    typedef std::mt19937 G;
    G g;
    D d(0, 1);
    const int N = 100000;
    std::vector<D::result_type> u;
    for (int i = 0; i < N; ++i)
    {
        D::result_type v = d(g);
        assert(d.min() <= v && v <= d.max());
        u.push_back(v);
    }
    double mean = std::accumulate(u.begin(), u.end(),
                                          double(0)) / u.size();
    double var = 0;
    double skew = 0;
    double kurtosis = 0;
    for (unsigned i = 0; i < u.size(); ++i)
    {
        double dbl = (u[i] - mean);
        double d2 = sqr(dbl);
        var += d2;
        skew += dbl * d2;
        kurtosis += d2 * d2;
    }
    var /= u.size();
//    double dev = std::sqrt(var);
    // In this case:
    //   skew     computes to 0./0. == nan
    //   kurtosis computes to 0./0. == nan
    //   x_skew     == -inf
    //   x_kurtosis == inf
    //   These tests are commented out because UBSan warns about division by 0
//    skew /= u.size() * dev * var;
//    kurtosis /= u.size() * var * var;
//    kurtosis -= 3;
    double x_mean = d.t() * d.p();
    double x_var = x_mean*(1-d.p());
//    double x_skew = (1-2*d.p()) / std::sqrt(x_var);
//    double x_kurtosis = (1-6*d.p()*(1-d.p())) / x_var;
    assert(mean == x_mean);
    assert(var == x_var);
//    assert(skew == x_skew);
//    assert(kurtosis == x_kurtosis);
}

void
test12()
{
    typedef std::binomial_distribution<> D;
    typedef std::mt19937 G;

    G g;
    D d(128738942, 1.6941441471907126e-08);

    std::string state = "1740222423 1665913615 1140355283 124152834 434145240"
                        "2553002688 4143320714 1810519474 447745536 1439409640 1596060396 1243637295"
                        "452117361 734967774 3276935081 35650473 682607275 4208082251 3209082916"
                        "638915489 4127185595 2859436515 309105096 837982734 796854873 4271538185"
                        "2447193692 607594006 4035165093 4230150671 2567368782 1000242037 2469514821"
                        "1843373462 1751084370 1033341643 3506396674 4169541123 1191187784 3479797390"
                        "3785371742 1475391851 878730063 2661164420 63166678 4127393159 2797714867"
                        "1295211604 2717051330 1009514623 1963164571 561646784 819612826 3340955171"
                        "1338523647 1675643732 458583760 698472119 3233594836 2901754568 4222994242"
                        "51167459 2501563254 2175997686 1673326467 3722097469 2183287831 2155925807"
                        "1071447253 1857934241 320830903 1514449149 103571877 839083116 3893321384"
                        "4236495022 766393502 2729490440 290181118 3191537542 1077578150 3066185245"
                        "3193085445 3786728494 2938418649 3410121447 1453867071 698346001 3037921161"
                        "839425565 2245305640 2806447261 3196149514 1071872132 2337761397 3632554165"
                        "190093341 4248613644 2372806256 3290113603 3852853233 272818390 3168842643"
                        "25788407 4197010683 3864965812 1635548247 2364439227 3344377087 4284620573"
                        "3351117493 3398532219 2757166123 1127999905 2988564217 3707129726 3652489018"
                        "4035370271 475801332 2109377392 2128345729 3920803035 4271338685 509459802"
                        "4158256844 1850467175 1579214935 8921175 4068350958 2951987840 506827330"
                        "3520651040 3359838267 1120109827 3917280670 2748947423 3672973280 1566164613"
                        "2986317531 1204099196 3080678121 3574913280 4009316336 3034181160 1818230129"
                        "3757769877 2464713972 2812294843 782960615 1228678223 2571358051 4260066020"
                        "2439643840 3500737183 1433940923 1031851687 190066625 3777385171 4142770213"
                        "3539275502 1622933657 425231043 3715607557 260333136 4198959706 358418"
                        "1799817566 2839827743 437785672 2967249029 949856347 2081447702 1102224171"
                        "479701434 1781895167 2965560025 264797633 2564778619 2515037023 1320978995"
                        "780140943 2372404879 3823445604 2917613108 143505740 3507288260 2803553229"
                        "4195962819 4072604717 3155823087 323755011 601944215 1840441037 2850820195"
                        "915623058 3306124208 3069788039 1553985704 411632899 3200645375 2973968812"
                        "4263574437 3360058162 144760024 845487010 3508028432 4091510967 3925394277"
                        "71566492 3432433113 3266920114 3539050491 51719451 1245373835 1469278112"
                        "3298302496 753088653 2942352102 1565378440 494477947 971879195 482756304"
                        "2475493857 143180757 324876427 1610205542 1829295320 1937949038 3733336232"
                        "2542145235 3636527510 2347609126 2343078538 2526896356 167862270 2299577281"
                        "3382958264 1911078293 531208917 3588214476 1086101513 1838672874 2119663667"
                        "491092052 2961424745 3048925589 486607333 3505822195 3888367 2949031946"
                        "2684841832 433147539 2333660325 3142554719 435207743 3063000516 4043979879"
                        "3290075088 1114755542 18368971 876637247 3352816011 1421909753 3339898083"
                        "740553432 3682683666 2699730850 2861403632 1971653904 900380480 2635160544"
                        "1318218867 411940 2141321523 2349820793 280562368 3816712514 3790707429"
                        "1619023591 2858103376 1462886666 1723686126 3766879240 1918781537 2792938366"
                        "166155425 803108075 722833545 220020495 880029214 2901984266 609985526"
                        "1367283597 132804580 903066665 131582208 64374393 2006102725 3422930158"
                        "4209296423 380263053 3978926691 3310851236 4245770487 4166043866 4080757525"
                        "3329599259 258706185 2452129516 3191265966 2958285912 1070664670 921876197"
                        "2421722823 2568477756 382467393 2196144533 213270233 116974426 2230947214"
                        "2576421741 393776471 2796472698 3647710433 3264988906 726903864 817800486"
                        "628224092 2707785007 3517963926 596980027 2466711387 3156540408 2517803670"
                        "3408123552 4142066739 3779818910 2988899011 2732117432 3579427018 1513070048"
                        "1566052861 20225341 997297613 3219855094 2777075639 1656025420 3670325076"
                        "1469330501 3061438653 4264717436 1305791144 1237197751 2943926634 1566843825"
                        "3359878993 4037226997 4044024653 3611863927 1375344610 211134383 2406252392"
                        "1349912770 1023874273 1912665158 1762983936 407124872 2936278199 1821966634"
                        "3337187112 2546090236 2594870585 823411965 126464686 4041388220 1686530706"
                        "2780657745 1945569350 203691199 2532411242 1830339266 674003798 2192329968"
                        "2425624005 2819484460 3743368462 2565769418 4179439526 216134386 2880090718"
                        "623297558 3913067470 745959159 2499436157 373025119 3423124368 2522302278"
                        "3719518513 999390119 159673547 228111094 3391079061 1761352720 2549048062"
                        "1125219697 2052834337 3743842626 2433549637 3636723358 1860785315 2387664013"
                        "581140755 11086848 4199179079 1180488689 2060816030 2550665319 1314472090"
                        "1402807876 304522082 3382175195 4260677857 1724818219 2183493354 1004322779"
                        "4166984056 889220724 553883566 582971548 2046113107 2080208105 3473121134"
                        "1959681858 1840897428 2595714120 855065022 4191762128 3679914005 3623561445"
                        "3437337182 3269107597 2019021510 2112281155 985458687 1364815423 514093990"
                        "3711847302 704129707 3398127374 517373404 2646977457 3048605419 1372350917"
                        "3831335422 2263542968 2283942504 2193996512 824623017 1707815852 3337156739"
                        "2301398895 2077322758 193542893 869960695 3878520140 403616946 3228943765"
                        "1037753596 2949947821 379992823 2251850209 1614533146 1704886337 108361232"
                        "3840616436 2932809257 2375700648 596391307 4226846855 191943050 1271990524"
                        "1335422537 3085696177 2030313449 3272604577 1148556450 1184357181 3558074012"
                        "3259720214 2755915415 2720703536 31861322 1740307221 1860884298 3922103763"
                        "4066872392 1756734488 394294796 2505236387 2456914682 639788702 52063410"
                        "2855173018 3307964490 556762160 3624145788 3793504468 4252003358 3690335184"
                        "688245281 2259823605 2617950220 1045718164 3091539813 1330130477 736722350"
                        "3100437052 3900855736 4183439368 1735720081 2644768495 819274730 2364834023"
                        "1393374098 981219339 3969251105 332522940 850159909 646738867 3413137687"
                        "1646732884 80027487 2196948979 5295580 3530173036 767814907 2573204209"
                        "491686200 1287955820 3095830596 2152743903 1738320986 1900678059 3613699900"
                        "3076191184 2917243255 2236492002 3504114019 604643631 3324769580 4078090927"
                        "1245379462 2026215662 1566278916 2832509655 3010562339 1269806412 835199342"
                        "2561789927 163108895 524878390 833167775 3551760739 3008059185 1133970834"
                        "26821616 2846321927 3803209991 581001826 3764614926 3893778555 617853085"
                        "183809431 3510530944 350044681 429839558 1238110552 265276207 205294443"
                        "3092821176 2003027316 2577165836 1277274629 87531073 63821123 354781812"
                        "3700767000 3451421881 990626144 3763226681 3373715717 2360928651 2412110189"
                        "3362121672 3080578947 1604861935 3186376735 2989392261 3550022914 756392571"
                        "1580512570 2584626785 2727753459 730699388 3379402897 3050444856 2244390108"
                        "3941150486 1990708800 2462735 195459645 761670582 1067695927 984662039"
                        "2678082647 1839150009 2113552968 406021267 2193154754 720977131 2445722325"
                        "2482507181 2062595810 1015226482";

    std::istringstream iss(state);
    iss >> g;

    const int N = 1000000;
    std::vector<D::result_type> u;
    for (int i = 0; i < N; ++i)
    {
        D::result_type v = d(g);
        assert(d.min() <= v && v <= d.max());
        u.push_back(v);
    }
    double mean = std::accumulate(u.begin(), u.end(),
                                          double(0)) / u.size();
    double var = 0;
    double skew = 0;
    double kurtosis = 0;
    for (unsigned i = 0; i < u.size(); ++i)
    {
        double dbl = (u[i] - mean);
        double d2 = sqr(dbl);
        var += d2;
        skew += dbl * d2;
        kurtosis += d2 * d2;
    }
    var /= u.size();
    double dev = std::sqrt(var);
    skew /= u.size() * dev * var;
    kurtosis /= u.size() * var * var;
    kurtosis -= 3;
    double x_mean = d.t() * d.p();
    double x_var = x_mean*(1-d.p());
    double x_skew = (1-2*d.p()) / std::sqrt(x_var);
    double x_kurtosis = (1-6*d.p()*(1-d.p())) / x_var;
    assert(std::abs((mean - x_mean) / x_mean) < 0.01);
    assert(std::abs((var - x_var) / x_var) < 0.01);
    assert(std::abs((skew - x_skew) / x_skew) < 0.01);
    assert(std::abs((kurtosis - x_kurtosis) / x_kurtosis) < 0.04);
}

int main(int, char**)
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
    test11();
    test12();

  return 0;
}

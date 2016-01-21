#include <iostream>
#include <string>
#include "SequenceMatcher.h"
#include <list>

void test_FindLongestMatch()
{
    std::string a = "qabxcd";
    std::string b = "abycdf";
    difflib::SequenceMatcher<std::string> sm(a, b);

    auto match = sm.FindLongestMatch(0, 9, 0, 8);
    auto matches = sm.GetMatchingBlocks();
    for (auto match : matches)
    {
        std::cout << match.besti << " " << match.bestj << " " << match.bestsize << std::endl;
    }
}

void test_GetOpcodes()
{
    std::string a = "qabxcd";
    std::string b = "abycdf";
    difflib::SequenceMatcher<std::string> sm(a, b);

    /*char arra[] = {'q', 'a', 'b', 'x', 'c', 'd'};
    char arrb[] = {'a', 'b', 'y', 'c', 'd', 'f'};
    std::vector<char> a(arra, arra+6);
    std::vector<char> b(arrb, arrb+6);
    difflib::SequenceMatcher<std::vector<char>> sm(a, b);*/

    auto ops = sm.GetOpcodes();
    for (auto op : ops)
    {
        std::cout /*<< "%7s a[%d:%d] (%s) b[%d:%d] (%s)" */
            << op.tag << " a[" << op.a1 << ":" << op.a2 << "] (" /*<< a.substr(op.a1, op.a2-op.a1)*/
            << ") b[" << op.b1 << ":" <<  op.b2 << "] (" /*<< b.substr(op.b1, op.b2-op.b1)*/ << ")" << std::endl;
    }
}

void test_GetGroupedOpcodes()
{
    /*char arra[] = {'q', 'a', 'b', 'x', 'c', 'd'};
    char arrb[] = {'a', 'b', 'y', 'c', 'd', 'f'};
    std::vector<char> a(arra, arra+6);
    std::vector<char> b(arrb, arrb+6);
    difflib::SequenceMatcher<std::vector<char>> sm(a, b);*/

	/*a = map(str, range(1,40))
	b = a[:]
	b[8:8] = ['i']     # Make an insertion
	b[20] += 'x'       # Make a replacement
	b[23:28] = []      # Make a deletion
	b[30] += 'y'       # Make another replacement*/

    std::vector<std::string> a;
    std::vector<std::string> b;
    for (int i = 1; i < 40; i++)
    {
        a.push_back(std::to_string(i));
        if (i == 8)
        {
            b.push_back(std::to_string(i));
            b.push_back("i");
        }
        else if (i == 20)
        {
            b.push_back(std::to_string(i) + "x");
        }
        else if ( i >= 23 && i < 28)
        {
        }
        else if (i == 35)
        {
            b.push_back(std::to_string(i) + "y");
        }
        else
        {
            b.push_back(std::to_string(i));
        }
    }

    difflib::SequenceMatcher<std::vector<std::string>> sm(a, b);
    auto gops = sm.GetGroupedOpcodes();
    for (auto gop : gops)
    {
        for (auto op : gop)
        {
            std::cout /*<< "%7s a[%d:%d] (%s) b[%d:%d] (%s)" */
            << op.tag << " a[" << op.a1 << ":" << op.a2 << "] (" /*<< a.substr(op.a1, op.a2-op.a1)*/
            << ") b[" << op.b1 << ":" <<  op.b2 << "] (" /*<< b.substr(op.b1, op.b2-op.b1)*/ << ")" << std::endl;
        }
        std::cout<< std::endl;
    }
}

void test_ratio()
{
    difflib::SequenceMatcher<std::string> sm("abcd", "bcde");
    std::cout<< sm.Ratio() << std::endl;
    std::cout<< sm.QuickRatio() << std::endl;
    std::cout<< sm.RealQuickRatio() << std::endl;
}

int main()
{
    /* 暂不支持list容器（无法使用operator[]）
    std::list<char> a(arra, arra+6);
    std::list<char> b(arrb, arrb+6);
    difflib::SequenceMatcher<std::list<char>> sm(a, b);*/

    // test_FindLongestMatch();
    // test_GetOpcodes();
    //test_GetGroupedOpcodes();
    test_ratio();

    return 0;
}


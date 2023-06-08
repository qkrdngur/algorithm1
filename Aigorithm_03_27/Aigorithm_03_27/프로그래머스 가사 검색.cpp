#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool comp(string a, string b)
{
    if (a.size() < b.size())
        return true;
    else if (a.size() == b.size())
    {
        if (a < b)
            return true;
    }
    else
        return false;
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;

    //이진 탐색
    vector<string> revwords = words;
    for (int i = 0; i < revwords.size(); i++)
        reverse(revwords[i].begin(), revwords[i].end());

    sort(words.begin(), words.end(), comp);
    sort(revwords.begin(), revwords.end(), comp);

    //우리가 분석해야하는 퀴리 사이즈만큼 늘린다.
    for (int i = 0; i < queries.size(); i++)
    {
        int low, high, idx;
        string strquery = queries[i];

        //??인 것에 a와 z로 넣는다.
        //1.?로 시작한경우
        if (strquery[0] == '?')
        {
            reverse(strquery.begin(), strquery.end());
            idx = strquery.find('?');
            for (int j = idx; j < strquery.length(); j++)
            {
                strquery[j] = 'a';
            }
            //lower_bound는 찾으려는 값 이상의 값이 처음 나타나는 위치
            low = lower_bound(revwords.begin(), revwords.end(), strquery, comp) - revwords.begin();
            //아닌 경우
            for (int j = idx; j < strquery.length(); j++)
            {
                strquery[j] = 'a';
            }
            //upper_bound는 찾으려는 값을 초과ㅏ하는 위치가 나옴.
            high = upper_bound(revwords.begin(), revwords.end(), strquery, comp) - revwords.begin();
        }
        else
        {
            idx = strquery.find('?');
            for (int j = idx; j < strquery.length(); j++)
            {
                strquery[j] = 'a';
            }
            low = lower_bound(words.begin(), words.end(), strquery, comp) - words.begin();
            for (int j = idx; j < strquery.length(); j++)
            {
                strquery[j] = 'z';
            }
            high = upper_bound(words.begin(), words.end(), strquery, comp) - words.begin();
        }
        answer.push_back(high - low);
    }
    //2. 그게 아닌 경우

    return answer;
}
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

    //���� Ž��
    vector<string> revwords = words;
    for (int i = 0; i < revwords.size(); i++)
        reverse(revwords[i].begin(), revwords[i].end());

    sort(words.begin(), words.end(), comp);
    sort(revwords.begin(), revwords.end(), comp);

    //�츮�� �м��ؾ��ϴ� ���� �����ŭ �ø���.
    for (int i = 0; i < queries.size(); i++)
    {
        int low, high, idx;
        string strquery = queries[i];

        //??�� �Ϳ� a�� z�� �ִ´�.
        //1.?�� �����Ѱ��
        if (strquery[0] == '?')
        {
            reverse(strquery.begin(), strquery.end());
            idx = strquery.find('?');
            for (int j = idx; j < strquery.length(); j++)
            {
                strquery[j] = 'a';
            }
            //lower_bound�� ã������ �� �̻��� ���� ó�� ��Ÿ���� ��ġ
            low = lower_bound(revwords.begin(), revwords.end(), strquery, comp) - revwords.begin();
            //�ƴ� ���
            for (int j = idx; j < strquery.length(); j++)
            {
                strquery[j] = 'a';
            }
            //upper_bound�� ã������ ���� �ʰ����ϴ� ��ġ�� ����.
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
    //2. �װ� �ƴ� ���

    return answer;
}
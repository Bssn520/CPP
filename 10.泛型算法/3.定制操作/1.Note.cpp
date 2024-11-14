/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-09 20:12:36
 * @LastEditTime: 2024-11-14 11:07:32
 * @Description:
 *
 */

/*
定制操作

1. 向算法传递函数

谓词

谓词是一个可以调用的表达式，其返回结果是一个能用作条件的值。
标准库算法所使用的谓词分为两类: 一元谓词(意味着它们只接受单一参数)、二元谓词(意味着它们有两个参数)。

sort 的重载版本, 按string长度来进行排序:
// 比较函数，用来按长度排序单词
bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}
// 按长度由短至长排序 words
sort(words.begin(), words.end(), isSorter);

排序算法

在我们将 words 按大小重排的同时，还希望具有相同长度的元素按字典序排列。为了保持相同长度的单词按字典序排列，可以使用 stable_sort 算法。这种稳定排序算法维持相等元素的原有顺序。

elimDups(words); // 将 words 按字典序重排，并消除重复单词
// 按长度重新排序，长度相同的单词维持字典序
stable_sort(words.begin(), words.end(), isShorter);
for (const auto &s : words)
    cout << s << " ";
cout << endl;

假定在此调用前words 是按字典序排列的，则调用之后，words 会按元素大小排序，而长度相同的单词会保持字典序。


*/

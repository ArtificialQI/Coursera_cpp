#include <algorithm>
#include <utility>
#include <string>


template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end, char prefix) {

    // ��� ������, ������������ � '<prefix>', ������ ��� ����� ������ "<prefix>"
    auto left = lower_bound(range_begin, range_end, string(1, prefix));

    // �������� ��������� � �������� ������.
    // �� �������, ���� prefix = 'z':
    // � ���� ������ �� ������� ��������� �� 'z' ������ � ������� ��������
    char next_prefix = static_cast<char>(prefix + 1);

    // ������ "<next_prefix>" � ������ ��������� �����
    // �������� ������ ������� ������
    // ��������� �����, ����������� � '<prefix>'
    auto right = lower_bound(range_begin, range_end, string(1, next_prefix));

    return { left, right };
}

#include <algorithm>
#include <utility>
#include <string>


template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end, string prefix) {

    // ��� ������, ������������ � prefix, ������ ��� ����� ������ "<prefix>"
    auto left = lower_bound(range_begin, range_end, prefix);

    // �������� ������, ������� � ������ ��������� ����� ��������
    // ������ ������� ������ ��������� �����, ������������ � prefix
    string upper_bound = prefix;
    ++upper_bound[upper_bound.size() - 1];

    // ������ ����������� �����, �� ������� upper_bound,
    // ����������� �������� ������ �������������
    auto right = lower_bound(range_begin, range_end, upper_bound);

    return { left, right };
}
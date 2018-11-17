// ����������, �������� �� ������ s �����������
bool IsPalindrom(string s) {

  // �������� ��� ������� s[i] �� ������ �������� ������
  for (size_t i = 0; i < s.size() / 2; ++i) {
    // s[s.size() - i - 1] � ������, ������������ ������� s[i]
    if (s[i] != s[s.size() - i - 1]) {
      return false;  // ���� ��� �� ���������, ������ ����� �� ���������
    }
  }

  // ���� ��� ���� �������� ���������, ������ � ���������
  return true;
}

vector<string> PalindromFilter(vector<string> words, int min_length) {
  vector<string> result;
  // ���������� ��� �������� ������� words
  for (auto s : words) {
    // ���� �������� ������� �����������, ��������� s � ������
    if (s.size() >= min_length && IsPalindrom(s)) {
      result.push_back(s);
    }
  }
  return result;
}

#include <exception>
#include <string>

using namespace std;

class TimeServer {
public:
  string GetCurrentTime() {
    // �������� ����� ������� AskTimeServer � try-catch ����
    try {
      last_fetched_time = AskTimeServer();
    } catch (const system_error&) {  // ����� ������ system_error
    }
    // ���������� �������� ���� � ���� ����������, ���� ���
    return last_fetched_time;
  }

private:
  string last_fetched_time = "00:00:00";
};

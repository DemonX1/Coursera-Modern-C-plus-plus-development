#include <string>

class INotifier {
public:
    virtual void Notify(const std::string& message) = 0;
};

class SmsNotifier : public INotifier{
public:
    SmsNotifier(const std::string &recipient)
        : __recipient(recipient) {

    }

    void Notify(const std::string &message) override {
        SendSms(__recipient, message);
    }

private:
    const std::string __recipient;
};

class EmailNotifier : public INotifier{
public:
    EmailNotifier(const std::string &recipient)
        : __recipient(recipient) {

    }

    void Notify(const std::string &message) override {
        SendEmail(__recipient, message);
    }

private:
    const std::string __recipient;
};

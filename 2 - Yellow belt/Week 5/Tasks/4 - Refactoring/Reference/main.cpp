#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Person {
public:
    Person(const string& job, const string& name) : Job(job), Name(name) {}

    virtual void Walk(const string& destination) const {
        PrintAction("walks to: " + destination);
    }

    const string& GetName() const {
        return Name;
    }

    const string& GetJob() const {
        return Job;
    }

protected:
    void PrintAction(const string& action) const {
        cout << GetJob() << ": " << GetName() << " " << action << endl;
    }

private:
    const string Job;
    const string Name;
};

class Student : public Person {
public:
    Student(const string& name, const string& favouriteSong)
            : Person("Student", name), FavouriteSong(favouriteSong) {}

    void Learn() const {
        PrintAction("learns");
    }

    void Walk(const string& destination) const override {
        Person::Walk(destination);
        SingSong();
    }

    void SingSong() const {
        PrintAction("sings a song: " + FavouriteSong);
    }

private:
    string FavouriteSong;
};


class Teacher : public Person {
public:
    Teacher(const string& name, const string& subject)
            : Person("Teacher", name), Subject(subject) {}

    void Teach() const {
        PrintAction("teaches: " + Subject);
    }

private:
    string Subject;
};


class Policeman : public Person {
public:
    Policeman(const string& name) : Person("Policeman", name) {}

    void Check(const Person& person) const {
        stringstream action;
        action << "checks " << person.GetJob() << ". "
               << person.GetJob() << "'s name is: " << person.GetName();
        PrintAction(action.str());
    }
};

void VisitPlaces(const Person& person, const vector<string>& places) {
    for (const string& place : places) {
        person.Walk(place);
    }
}

int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}

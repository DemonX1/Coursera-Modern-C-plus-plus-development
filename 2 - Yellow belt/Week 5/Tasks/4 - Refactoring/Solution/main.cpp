#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <exception>

class Person {
public:
    enum class Occupation {
        Student,
        Teacher,
        Policeman
    };

    Person(const std::string &name, const Occupation &occupation)
        : __name(name) , __occupation(occupation) {
    }

    inline std::string getName() const {
        return __name;
    }

    inline std::string getOccupation() const {
        switch (__occupation) {
            case Person::Occupation::Student:
                return "Student";
                break;
            case Person::Occupation::Teacher:
                return "Teacher";
                break;
            case Person::Occupation::Policeman:
                return "Policeman";
                break;
            default:
                throw std::invalid_argument("Unknown or unimplemented occupation");
        }
    }

    virtual void Walk(const std::string &destination) const {
        std::cout << getOccupation() << ": " << getName() << " walks to: " << destination << std::endl;
    }

protected:
    const std::string __name;
    const Person::Occupation __occupation;
};

class Student : public Person {
public:
    Student(const std::string &name, const std::string &favourite_song)
        : Person(name, Person::Occupation::Student), __favourite_song(favourite_song) {
    }

    void Learn() const {
        std::cout << "Student: " << __name << " learns" << std::endl;
    }

    void Walk(const std::string &destination) const override {
        std::cout << "Student: " << getName() << " walks to: " << destination << std::endl;
        std::cout << "Student: " << getName() << " sings a song: " << __favourite_song << std::endl;
    }

private:
    const std::string __favourite_song;
};

class Teacher : public Person {
public:
    Teacher(const std::string &name, const std::string &subject)
        : Person(name, Person::Occupation::Teacher), __subject(subject) {
    }

    void Teach() const {
        std::cout << "Teacher: " << getName() << " teaches: " << __subject << std::endl;
    }

private:
    const std::string __subject;
};

class Policeman : public Person {
public:
    Policeman(const std::string &name)
        : Person(name, Person::Occupation::Policeman) {
    }

    void Check(const Person &p) const {
        std::cout << "Policeman: " << getName() << " checks " << p.getOccupation() << ". " << p.getOccupation() << "'s name is: " << p.getName() << std::endl;
    }
};

void VisitPlaces(const Person &person, const std::vector < std::string > &places) {
    for (const auto &place: places) {
        person.Walk(place);
    }

    return;
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

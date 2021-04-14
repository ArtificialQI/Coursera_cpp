#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
public:
    Person(const string& name, const string& status) : Name(name), Status(status) {}
    
    void Walk(const string& destination) const {
    cout << Status << ": " << Name << " walks to: " << destination << endl;
    }

protected:
    const string Name;
    const string Status;

friend class Policeman;
};

class Student : public Person {
public:

    Student(const string& name, const string& favouriteSong) : Person(name, "Student"),
    FavouriteSong(favouriteSong) {}

    void Learn() const {
        cout << Status << ": " << Name << " learns" << endl;
    }

    void SingSong() const {
        cout << Status << ": " << Name << " sings a song: " << FavouriteSong << endl;
    }

private:
    const string FavouriteSong;
};


class Teacher : public Person {
public:

    Teacher(const string& name, const string& subject) : Person(name, "Teacher"), Subject(subject) {}

    void Teach() const {
        cout << Status <<": " << Name << " teaches: " << Subject << endl;
    }

private:
    const string Subject;
};


class Policeman : public Person {
public:
    Policeman(const string& name) : Person(name, "Policeman") {}

    void Check(const Person& p) const {
        cout << Status << ": " << Name << " checks " << p.Status
        << ". " << p.Status << "'s name is: " << p.Name << endl;
    }
};


void VisitPlaces(const Person& person, const vector<string>& places) {
    for (const auto& p : places) {
        person.Walk(p);
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

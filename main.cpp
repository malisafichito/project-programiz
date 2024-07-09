void print_students(const std::vector<Student>& students) {
    for (size_t i = 0; i < students.size(); ++i) {
        std::cout << "Student " << i + 1 << ":\n"
                  << "Firstname: " << students[i].firstname << "\n"
                  << "Surname: " << students[i].surname << "\n"
                  << "Gender: " << (students[i].gender == Gender::MALE ? "Male" : "Female") << "\n"
                  << "Age: " << students[i].age << "\n"
                  << "BBIT Group: " << students[i].bbit_group << "\n"
                  << "Activities: ";
        for (const auto& activity : students[i].activities) {
            std::cout << (activity == ActivityType::CLUB ? "Club" : "Sport") << " ";
        }
        std::cout << "\n\n";
    }
}

void print_clubs(const std::vector<Club>& clubs) {
    for (size_t i = 0; i < clubs.size(); ++i) {
        std::cout << "Club " << i + 1 << ":\n"
                  << "Name: " << clubs[i].name << "\n"
                  << "Capacity: " << clubs[i].capacity << "\n"
                  << "Male Count: " << clubs[i].male_count << "\n"
                  << "Female Count: " << clubs[i].female_count << "\n\n";
    }
}

void print_sports(const std::vector<Sport>& sports) {
    for (size_t i = 0; i < sports.size(); ++i) {
        std::cout << "Sport " << i + 1 << ":\n"
                  << "Name: " << sports[i].name << "\n"
                  << "Capacity: " << sports[i].capacity << "\n"
                  << "Male Count: " << sports[i].male_count << "\n"
                  << "Female Count: " << sports[i].female_count << "\n\n";
    }
}

void save_data(const std::vector<Student>& students, const std::vector<Club>& clubs, const std::vector<Sport>& sports) {
    std::ofstream file("data.csv");
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file for writing.\n";
        return;
    }

    file << "Firstname,Surname,Gender,Age,BBIT Group,Activities\n";
    for (const auto& student : students) {
        file << student.firstname << "," << student.surname << ","
             << (student.gender == Gender::MALE ? "Male" : "Female") << "," << student.age << ","
             << student.bbit_group << ",";
        for (const auto& activity : student.activities) {
            file << (activity == ActivityType::CLUB ? "Club" : "Sport") << " ";
        }
        file << "\n";
    }

    file << "Club Name,Capacity,Male Count,Female Count\n"
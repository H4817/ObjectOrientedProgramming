#define BOOST_TEST_MODULE MyTestModule

#include <boost/test/included/unit_test.hpp>

#include "Person.h"
#include "Worker.h"
#include "Teacher.h"
#include "Pupil.h"
#include "Student.h"
#include "AdvancedStudent.h"

struct PeopleFixture
{
    std::string firstName;
    std::string secondName;
    std::string patronymic;
    std::string address;
    CWorker worker;
    CTeacher teacher;
    CPupil pupil;
    CStudent student;
    CAdvancedStudent advancedStudent;
};

BOOST_FIXTURE_TEST_SUITE(without_parameters, PeopleFixture)
    BOOST_AUTO_TEST_SUITE(worker_tests)

        BOOST_AUTO_TEST_CASE(check_profession)
        {
            std::string profession("programmer");
            worker.SetProfession(profession);
            BOOST_CHECK(worker.GetProfession() == profession);
        }

        BOOST_AUTO_TEST_CASE(check_first_name)
        {
            firstName = "Vladimir";
            worker.SetFirstName(firstName);
            BOOST_CHECK(worker.GetFirstName() == firstName);
        }

        BOOST_AUTO_TEST_CASE(check_second_name)
        {
            secondName = "Filatov";
            worker.SetSecondName(secondName);
            BOOST_CHECK(worker.GetSecondName() == secondName);
        }

        BOOST_AUTO_TEST_CASE(check_patronymic)
        {
            patronymic = "Ivanovich";
            worker.SetPatronymic(patronymic);
            BOOST_CHECK(worker.GetPatronymic() == patronymic);
        }

        BOOST_AUTO_TEST_CASE(check_address)
        {
            address = "Moscow";
            worker.SetAddress(address);
            BOOST_CHECK(worker.GetAddress() == address);
        }

    BOOST_AUTO_TEST_SUITE_END()

    BOOST_AUTO_TEST_SUITE(teacher_tests)

        BOOST_AUTO_TEST_CASE(check_name_of_school_subject)
        {
            std::string nameOfSchoolSubject("biology");
            teacher.SetNameOfSchoolSubject(nameOfSchoolSubject);
            BOOST_CHECK(teacher.GetNameOfSchoolSubject() == nameOfSchoolSubject);
        }

        BOOST_AUTO_TEST_CASE(check_first_name)
        {
            firstName = "Elena";
            teacher.SetFirstName(firstName);
            BOOST_CHECK(teacher.GetFirstName() == firstName);
        }

        BOOST_AUTO_TEST_CASE(check_second_name)
        {
            secondName = "Filatova";
            teacher.SetSecondName(secondName);
            BOOST_CHECK(teacher.GetSecondName() == secondName);
        }

        BOOST_AUTO_TEST_CASE(check_patronymic)
        {
            patronymic = "Sergeyevna";
            teacher.SetPatronymic(patronymic);
            BOOST_CHECK(teacher.GetPatronymic() == patronymic);
        }

        BOOST_AUTO_TEST_CASE(check_address)
        {
            address = "Moscow";
            teacher.SetAddress(address);
            BOOST_CHECK(teacher.GetAddress() == address);
        }

    BOOST_AUTO_TEST_SUITE_END()

    BOOST_AUTO_TEST_SUITE(pupil_tests)

        BOOST_AUTO_TEST_CASE(check_name_of_school)
        {
            std::string nameOfSchool("21");
            pupil.SetNameOfSchool(nameOfSchool);
            BOOST_CHECK(pupil.GetNameOfSchool() == nameOfSchool);
        }

        BOOST_AUTO_TEST_CASE(check_name_of_class)
        {
            std::string nameOfClass("441");
            pupil.SetNameOfClass(nameOfClass);
            BOOST_CHECK(pupil.GetNameOfClass() == nameOfClass);
        }

        BOOST_AUTO_TEST_CASE(check_first_name)
        {
            firstName = "Dima";
            pupil.SetFirstName(firstName);
            BOOST_CHECK(pupil.GetFirstName() == firstName);
        }

        BOOST_AUTO_TEST_CASE(check_second_name)
        {
            secondName = "Filatov";
            pupil.SetSecondName(secondName);
            BOOST_CHECK(pupil.GetSecondName() == secondName);
        }

        BOOST_AUTO_TEST_CASE(check_patronymic)
        {
            patronymic = "Vladimirovich";
            pupil.SetPatronymic(patronymic);
            BOOST_CHECK(pupil.GetPatronymic() == patronymic);
        }

        BOOST_AUTO_TEST_CASE(check_address)
        {
            address = "Moscow";
            pupil.SetAddress(address);
            BOOST_CHECK(pupil.GetAddress() == address);
        }

    BOOST_AUTO_TEST_SUITE_END()

    BOOST_AUTO_TEST_SUITE(student_tests)

        BOOST_AUTO_TEST_CASE(check_name_of_college)
        {
            std::string nameOfCollege("Volgatech");
            student.SetNameOfCollege(nameOfCollege);
            BOOST_CHECK(student.GetNameOfCollege() == nameOfCollege);
        }

        BOOST_AUTO_TEST_CASE(check_number_of_students_card)
        {
            std::string numberOfStudentsCard("156224774");
            student.SetNumberOfStudentsCard(numberOfStudentsCard);
            BOOST_CHECK(student.GetNumberOfStudentsCard() == numberOfStudentsCard);
        }

        BOOST_AUTO_TEST_CASE(check_first_name)
        {
            firstName = "Ivan";
            student.SetFirstName(firstName);
            BOOST_CHECK(student.GetFirstName() == firstName);
        }

        BOOST_AUTO_TEST_CASE(check_second_name)
        {
            secondName = "Sidorov";
            student.SetSecondName(secondName);
            BOOST_CHECK(student.GetSecondName() == secondName);
        }

        BOOST_AUTO_TEST_CASE(check_patronymic)
        {
            patronymic = "Ivanovich";
            student.SetPatronymic(patronymic);
            BOOST_CHECK(student.GetPatronymic() == patronymic);
        }

        BOOST_AUTO_TEST_CASE(check_address)
        {
            address = "Yoshkar-Ola, eshkinina 24-22";
            student.SetAddress(address);
            BOOST_CHECK(student.GetAddress() == address);
        }
    BOOST_AUTO_TEST_SUITE_END()

    BOOST_AUTO_TEST_SUITE(advanced_student_tests)

        BOOST_AUTO_TEST_CASE(check_name_of_college)
        {
            std::string nameOfCollege("Volgatech");
            advancedStudent.SetNameOfCollege(nameOfCollege);
            BOOST_CHECK(advancedStudent.GetNameOfCollege() == nameOfCollege);
        }

        BOOST_AUTO_TEST_CASE(check_number_of_students_card)
        {
            std::string numberOfStudentsCard("156124514");
            advancedStudent.SetNumberOfStudentsCard(numberOfStudentsCard);
            BOOST_CHECK(advancedStudent.GetNumberOfStudentsCard() == numberOfStudentsCard);
        }

        BOOST_AUTO_TEST_CASE(check_subject_of_dissertation)
        {
            std::string subjectOfDissertation("artificial intelligence");
            advancedStudent.SetSubjectOfDissertation(subjectOfDissertation);
            BOOST_CHECK(advancedStudent.GetSubjectOfDissertation() == subjectOfDissertation);
        }

        BOOST_AUTO_TEST_CASE(check_first_name)
        {
            firstName = "Ivan";
            advancedStudent.SetFirstName(firstName);
            BOOST_CHECK(advancedStudent.GetFirstName() == firstName);
        }

        BOOST_AUTO_TEST_CASE(check_second_name)
        {
            secondName = "Sidorov";
            advancedStudent.SetSecondName(secondName);
            BOOST_CHECK(advancedStudent.GetSecondName() == secondName);
        }

        BOOST_AUTO_TEST_CASE(check_patronymic)
        {
            patronymic = "Ivanovich";
            advancedStudent.SetPatronymic(patronymic);
            BOOST_CHECK(advancedStudent.GetPatronymic() == patronymic);
        }

        BOOST_AUTO_TEST_CASE(check_address)
        {
            address = "Yoshkar-Ola, eshkinina 24-22";
            advancedStudent.SetAddress(address);
            BOOST_CHECK(advancedStudent.GetAddress() == address);
        }

    BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()

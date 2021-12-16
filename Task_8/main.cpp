#include <iostream>
#include <vector>
#include <tuple>
#include <fstream>
#include <sstream>

#include "College.pb.h"

class IRepository {
    virtual void Open() = 0; // бинарная десериализация в файл
    virtual void Save() = 0; // бинарная сериализация в файл
};

class IMethods {
    virtual double GetAverageScore(const College::Fullname& name) = 0;
    virtual std::string GetAllInfo(const College::Fullname& name) = 0;
    virtual std::string GetAllInfo() = 0;
};

class StudentsGroup : public IRepository, IMethods{
    College::StudentsGroup sg;
public:
    void Open(){
        std::ifstream file{"serializedOutput.bin", std::ios_base::binary};
        if(file.is_open()){
            sg.ParseFromIstream(&file);
        }
        file.close();
    };
    void Save(){
        std::ofstream out{"serializedSavedOutput.bin", std::ios_base::binary};
        if(out.is_open()){
            sg.SerializePartialToOstream(&out);
        }
        out.close();

    };
    double GetAverageScore(const College::Fullname& name){
        auto nameTuple = std::make_tuple(name.surname(), name.name(),
                                name.has_middlename() ? name.middlename() : "");

        for(size_t i = 0; i < sg.pupils_size(); ++i){
           if (std::make_tuple(sg.pupils(i).studentname().surname(),
                sg.pupils(i).studentname().name(),
                sg.pupils(i).studentname().has_middlename() ?
                sg.pupils(i).studentname().middlename() : "" ) == nameTuple){
               return sg.pupils(i).averagescore();
           }
        }
        return 0.0;
    };

    std::string GetAllInfo(const College::Fullname& name){
        auto nameTuple = std::make_tuple(name.surname(), name.name(),
                                name.has_middlename() ? name.middlename() : "");
        for(size_t i = 0; i < sg.pupils_size(); ++i){
           if (std::make_tuple(sg.pupils(i).studentname().surname(),
                sg.pupils(i).studentname().name(),
                sg.pupils(i).studentname().has_middlename() ?
                sg.pupils(i).studentname().middlename() : "" ) == nameTuple){
               std::stringstream ss;
               ss << name.surname() << " " << name.name();
               if(name.has_middlename()){
                   ss << " " << name.middlename() ;
               }
               ss << " Students scores:";
               for(size_t j = 0; j < sg.pupils(i).score_size(); ++j){
                   ss << " " << sg.pupils(i).score(j);
               }
               ss << " Avg score " << sg.pupils(i).averagescore();
               return ss.str();
           }
        }
        return "";
    };
    std::string GetAllInfo(){
        std::stringstream ss;
        for(size_t i = 0; i < sg.pupils_size(); ++i){
            ss << sg.pupils(i).studentname().surname() << " "
                                           << sg.pupils(i).studentname().name();
            if(sg.pupils(i).studentname().has_middlename()){
                ss << " " << sg.pupils(i).studentname().middlename() ;
            }
            ss << " Students scores:";
            for(size_t j = 0; j < sg.pupils(i).score_size(); ++j){
                ss << " " << sg.pupils(i).score(j);
            }
            ss << " Avg score " << sg.pupils(i).averagescore() << std::endl;
        }
        return ss.str();
    }
};



int main()
{
    {
        College::Fullname f;
        College::Fullname f1;
        College::Student st;
        College::Student st1;
        College::StudentsGroup sg;

        f.set_name("Ivan");
        f.set_surname("Ivanov");

        st.set_allocated_studentname(&f);
        std::vector<int> scoreVec {5,4,5,3,4};
        st.mutable_score()->Add(scoreVec.begin(), scoreVec.end());
        st.set_averagescore(4.6);

        f1.set_name("Anton");
        f1.set_surname("Antonov");
        f1.set_middlename("Antonovich");

        st1.set_allocated_studentname(&f1);
        std::vector<int> scoreVec1 {5,5,5,5,5};
        st1.mutable_score()->Add(scoreVec1.begin(), scoreVec1.end());
        st1.set_averagescore(5.0);


        sg.add_pupils()->CopyFrom(st);
        sg.add_pupils()->CopyFrom(st1);

        std::ofstream of{"serializedOutput.bin", std::ios_base::binary};
        if(of.is_open()){
            sg.SerializePartialToOstream(&of);
        }
        of.close();
    }
    //===================================================
    {
        StudentsGroup sg;
        sg.Open();
        std::cout << sg.GetAllInfo() << std::endl;
        sg.Save();
        College::Fullname f;
        f.set_name("Anton");
        f.set_surname("Antonov");
        f.set_middlename("Antonovich");
        std::cout << sg.GetAllInfo(f) << std::endl;
        std::cout << sg.GetAverageScore(f) << std::endl;
    }
    return 0;
}

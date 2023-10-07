#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    :AForm("S_Form", 145, 137), targetName("default")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string targetName)
    :AForm("S_Form", 145, 137), targetName(targetName)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &Sref)
    :AForm(Sref.getName(), Sref.getSignGrade(), Sref.getExecGrade()), targetName(Sref.targetName)
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &Sref)
{
    if(this != &Sref)
    {   
        targetName = Sref.targetName;
        setName(Sref.getName());
        setExecGrade(Sref.getExecGrade());
        setSignGrade(Sref.getSignGrade());
        setSign(Sref.getSigned());
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    std::string file;
    std::ofstream ofs;
    file = this->targetName;
    file.append("_shrubbery");
    ofs.open(file);
    ofs <<  "                                                     \n"
            "                                                    .\n"
            "                                    .         \n"
            "        .              .              ;%     ;;\n"
            "            ,           ,                :;%  %;\n"
            "            :         ;                   :;%;'     .,\n"
            "    ,.        %;     %;            ;        %;'    ,;\n"
            "    ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
            "    %;       %;%;      ,  ;       %;  ;%;   ,%;'\n"
            "        ;%;      %;        ;%;        % ;%;  ,%;'\n"
            "        `%;.     ;%;     %;'         `;%%;.%;'\n"
            "        `:;%.    ;%%. %@;        %; ;@%;%'\n"
            "            `:%;.  :;bd%;          %;@%;'\n"
            "            `@%:.  :;%.         ;@@%;'\n"
            "                `@%.  `;@%.      ;@@%;\n"
            "                `@%%. `@%%    ;@@%;\n"
            "                    ;@%. :@%%  %@@%;\n"
            "                    %@bd%%%bd%%:;\n"
            "                       #@%%%%%:;;\n"
            "                       %@@%%%::;\n"
            "                       %@@@%(o);  . '\n"
            "                       %@@@o%;:(.,'\n"
            "                    `..%@@@o%::;\n"
            "                       `)@@@o%::;\n"
            "                       %@@(o)::;\n"
            "                       .%@@@@%::;\n"
            "                       ;%@@@@%::;.\n"
            "                      ;%@@@@%%:;;;.\n"
            "                  ...;%@@@@@%%:;;;;,..\n";
    ofs.close();
    std::cout << executor.getName() << " executed " << this->getName() << std::endl;
}

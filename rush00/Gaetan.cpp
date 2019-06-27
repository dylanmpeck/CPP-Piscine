#include "Gaetan.hpp"

Gaetan::Gaetan() : Enemy(2, 4)
{
	this->height = 44;
	this->width = 78;
	this->score = 100;
	this->health = 25;
}

Gaetan::Gaetan(const Gaetan& Gaetan) : Enemy(Gaetan)
{
}

Gaetan::~Gaetan()
{
	return;
}

Gaetan &Gaetan::operator=(const Gaetan& Gaetan)
{
	Enemy::operator=(Gaetan);
	return *this;
}

void Gaetan::tick()
{
	Enemy::tick();
    attron(COLOR_PAIR(1));

	std::string g00 = "                               (% ((##&%&%%###%                                ";
	std::string g01 = "                               %%(#&&@&&@@&&&&&%%                            ";
	std::string g02 = "                           ((%#&&@@@@@&@@@&@@@@&&&&%%                          ";
	std::string g03 = "                           &&&&&&@@&@&@&&@@&@@@&@@&%#(#                        ";
	std::string g04 = "                         %&&&&&&%(( ( ((((###%%&&@@@&                        ";
	std::string g05 = "                       &&&%%%# ****,,,,,,*****    (#@&@&%                      ";
	std::string g06 = "                      %%# ( **,,,*,,,,,,,,********   (&&&&(                    ";
	std::string g07 = "                    %&&(***,,,*,,,,,,,,,,,,*******    (&@@&                    ";
	std::string g08 = "                   && **,,,,,,,,,,,,,,,,,,,,*****    (&&&&                   ";
	std::string g09 = "                  (&%#(*,,,,,,,,,,,,,,,,,,,,,,***  * *  %&&&&                  ";
	std::string g10 = "                  &&%(*,,,,,,,,,,,,,,,,,,,,,,,***     * (%&@&                  ";
	std::string g11 = "                  &%# ,,,,,,,,,,,,,,,,,,,,,,,,****** *   #%&&%                 ";
	std::string g12 = "                 (&%#,,,,,*****  **,,,,,,,,,** (((((      #&&&                 ";
	std::string g13 = "                 #&%*,**  (((##    *,,,,,*  (####((###(  *(&&&                 ";
	std::string g14 = "                 %%%****,,,,,,,*** *,,,,,** ( *********  * %&&                 ";
	std::string g15 = "                 %&& ,,,,,**%%&(  *,,,**(##(%&(&&((*,*** %&&                 ";
	std::string g16 = "                 %%%(,,,,******** ***,,,**    ***    (****(&&&                 ";
	std::string g17 = "               * , #(,,,,,,,,,,,,,,,,,,********,,********* %(*(*               ";
	std::string g18 = "               ,(*,* *,,,,,,,,,,.,,,,,,*  ***,,,,,,******** ,*((               ";
	std::string g19 = "               , *,***,,,.,,,,,,,,,,,,,*    **,,,,,,***** **** (*              ";
	std::string g20 = "              * ,,* ,*,,,,,..,,,,,,,,,,***** ******,****** ,  *                ";
	std::string g21 = "                *,  ,*,,,,,.,,,,,*, ( ** ((  *************** ***              ";
	std::string g22 = "                 *,,**,,,,,,,,,,,,,,,****  *********,******,,**                ";
	std::string g23 = "                  *,,,,,,,,,,,,,,,,,***,,** ********,******,*                  ";
	std::string g24 = "                   ,,**,,,,,,,,,,,,,,********    ******** ,,**                 ";
	std::string g25 = "                      *,,,,,,,,***((((((  ((##(************                    ";
	std::string g26 = "                       *,,..,,,,,,,,,***************,** **                 ";
	std::string g27 = "                       **,,,,,,,,,,,,**************,,******            ";
	std::string g28 = "                       ***,,,,,,,,,,,,,*,*****************              ";
	std::string g29 = "                       *****,,,,,,,,,,,,******************              ";
	std::string g30 = "                        ****  ****,,,******* ***  ****    ) ";
	std::string g31 = "                      *  ***   ( (                 ** ";
	std::string g32 = "                         *****    ((######(((      **";
	std::string g33 = "                         **,,***      (             *  *(";
	std::string g34 = "                       * **,,,,***********     (        **";
	std::string g35 = "                        ****,,*,*********   ((((       (";
	std::string g36 = "                   &&@%****,,,,,,,*******   (((        ((@(";
	std::string g37 = "                &@&@@@@**,,,,,,,,,,,*******             (#@@%";
	std::string g38 = "            @@@&&@@@@@@@%,,,,,,,,,,,,,,,********  (#    &@@@@@@@& ";
	std::string g39 = "        %&@@@@@@&@@@@@@@@@@#,,,,,,,,,,,,*******       &@@@@@@@@@@@@&(";
	std::string g40 = "        @@@@&@@@@@@@@@@@@@@@@@@@@&%********,***  #@@@@@@@@@@@@@@@&@@@@@@&( ";
	std::string g41 = "     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	mvaddstr(position.getY() - 41, position.getX(), g00.c_str());
	mvaddstr(position.getY() - 40, position.getX(), g01.c_str());
	mvaddstr(position.getY() - 39, position.getX(), g02.c_str());
	mvaddstr(position.getY() - 38, position.getX(), g03.c_str());
	mvaddstr(position.getY() - 37, position.getX(), g04.c_str());
	mvaddstr(position.getY() - 36, position.getX(), g05.c_str());
	mvaddstr(position.getY() - 35, position.getX(), g06.c_str());
	mvaddstr(position.getY() - 34, position.getX(), g07.c_str());
	mvaddstr(position.getY() - 33, position.getX(), g08.c_str());
	mvaddstr(position.getY() - 32, position.getX(), g09.c_str());
	mvaddstr(position.getY() - 31, position.getX(), g10.c_str());
	mvaddstr(position.getY() - 30, position.getX(), g11.c_str());
	mvaddstr(position.getY() - 29, position.getX(), g12.c_str());
	mvaddstr(position.getY() - 28, position.getX(), g13.c_str());
	mvaddstr(position.getY() - 27, position.getX(), g14.c_str());
	mvaddstr(position.getY() - 26, position.getX(), g15.c_str());
	mvaddstr(position.getY() - 25, position.getX(), g16.c_str());
	mvaddstr(position.getY() - 24, position.getX(), g17.c_str());
	mvaddstr(position.getY() - 23, position.getX(), g18.c_str());
	mvaddstr(position.getY() - 22, position.getX(), g19.c_str());
	mvaddstr(position.getY() - 21, position.getX(), g20.c_str());
	mvaddstr(position.getY() - 20, position.getX(), g21.c_str());
	mvaddstr(position.getY() - 19, position.getX(), g22.c_str());
	mvaddstr(position.getY() - 18, position.getX(), g23.c_str());
	mvaddstr(position.getY() - 17, position.getX(), g24.c_str());
	mvaddstr(position.getY() - 16, position.getX(), g25.c_str());
	mvaddstr(position.getY() - 15, position.getX(), g26.c_str());
	mvaddstr(position.getY() - 14, position.getX(), g27.c_str());
	mvaddstr(position.getY() - 13, position.getX(), g28.c_str());
	mvaddstr(position.getY() - 12, position.getX(), g29.c_str());
	mvaddstr(position.getY() - 11, position.getX(), g30.c_str());
	mvaddstr(position.getY() - 10, position.getX(), g31.c_str());
	mvaddstr(position.getY() - 9, position.getX(), g32.c_str());
	mvaddstr(position.getY() - 8, position.getX(), g33.c_str());
	mvaddstr(position.getY() - 7, position.getX(), g34.c_str());
	mvaddstr(position.getY() - 6, position.getX(), g35.c_str());
	mvaddstr(position.getY() - 5, position.getX(), g36.c_str());
	mvaddstr(position.getY() - 4, position.getX(), g37.c_str());
	mvaddstr(position.getY() - 3, position.getX(), g38.c_str());
	mvaddstr(position.getY() - 2, position.getX(), g39.c_str());
	mvaddstr(position.getY() - 1, position.getX(), g40.c_str());
	mvaddstr(position.getY() - 0, position.getX(), g41.c_str());
    attroff(COLOR_PAIR(1));
}

GameEntity * Gaetan::clone()
{
	return (new Gaetan(*this));
}
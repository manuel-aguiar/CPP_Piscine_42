#ifndef WEAPON_HPP

# define WEAPON_HPP

#include <string>

class Weapon
{

    public:
        Weapon (const std::string& type);
        Weapon (const Weapon &copy);
        ~Weapon ();
        Weapon& operator= (const Weapon &copy);

        const std::string&      getType() const;
        void                    setType(const std::string& type);

    private:
        std::string     type;
		//Weapon();


};

















#endif

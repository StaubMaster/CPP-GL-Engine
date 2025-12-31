#ifndef  CONTAINER_BEHAVIOUR_SHOW_HPP
# define CONTAINER_BEHAVIOUR_SHOW_HPP

# include "Behaviour/Increase.hpp"
# include "Behaviour/Decrease.hpp"
# include "Behaviour/Memory.hpp"

# include <iosfwd>

std::ostream & operator <<(std::ostream & o, const Container::Behaviour::EIncrease & val);
std::ostream & operator <<(std::ostream & o, const Container::Behaviour::EDecrease & val);
std::ostream & operator <<(std::ostream & o, const Container::Behaviour::EMemory & val);

#endif
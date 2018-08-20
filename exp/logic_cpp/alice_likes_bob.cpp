// people
class Alice{};
class Bob{};
class George{};
class Steven{};

// languages
class Cpp{};
class Prolog{};
class Assembly{};

// facts
void kind(Bob);
void kind(George);
void kind(Steven);
void intelligent(Bob);
void intelligent(Steven);
void writes(Bob, Cpp);
void writes(Bob, Assembly);
void writes(George, Cpp);
void writes(Steven, Prolog);

// rule
template <typename Person> void likes(Alice, Person person)
{
    kind(person);
    intelligent(person);
    writes(person, Cpp());
}

// check the rule for Bob
int main()
{
    likes(Alice(), Bob());
}

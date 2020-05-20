#include <exception>

class eroare : public std::exception {
public:
  eroare () noexcept {}

  eroare (const eroare&) noexcept = default;

  eroare& operator= (const eroare&) noexcept = default;

  virtual ~eroare() noexcept = default;

  virtual const char* what() const noexcept {
    return "     Lista sau masina nu exista!\n     Incercati din nou!\n     Folositi comanda 'Afiseaza lista de masini' pentru ajutor.\n\n ";
  }
};


def zapytaj_figura(pytanie):
    print("Jakiej figury chcesz uzyskać " + pytanie + "?\n1. Kwadratu\n2. Prostokąta\n3. Trójkąta\n4. Koła\n5. Trapezu")
    return int(input("Podaj numer: "))


def zapytaj_bryla(pytanie):
    print("Jakiej bryły chcesz uzyskać " + pytanie + "?\n1. Sześcian\n2. Prostopadłościan\n3. Stożek\n4. Walec\n5. Kula")
    return int(input("Podaj numer: ")) + 5


def zapytaj_zmienne(figura):
    if figura == 1:
        return int(input("Wprowadź bok kwadratu: "))
    if figura == 2:
        return int(input("Wprowadź pierwszy bok prostokąta: ")), int(input("Wprowadź drugi bok prostokąta: "))
    if figura == 3:
        return int(input("Wprowadź bok trójkąta: ")), int(input("Wprowadź wysokość trójkąta: "))
    if figura == 4:
        return int(input("Wprowadź promień: "))
    if figura == 5:
        return int(input("Wprowadź pierwszy bok trapezu: ")), int(input("Wprowadź drugi bok trapezu: ")), int(input("Wprowadź wysokość trapezu: "))
    if figura == 6:
        return int(input("Wprowadź bok sześcianu: "))
    if figura == 7:
        return int(input("Wprowadź bok podstawy prostopadłościanu: ")), int(input("Wprowadź wysokość prostopadłościanu: "))
    if figura == 8:
        return int(input("Wprowadź promień podstawy stożka: ")), int(input("Wprowadź wysokość stożka: "))
    if figura == 9:
        return int(input("Wprowadź promień podstawy walca: ")), int(input("Wprowadź wysokość walca: "))
    if figura == 10:
        return int(input("Wprowadź promień kuli: "))


def pkwadrat(a):
    return a * a


def okwadrat(a):
    return a * 4


def pprostokat(a, b):
    return a * b


def oprostokat(a, b):
    return 2 * (a + b)


def ptrojkat(a, h):
    return a * h / 2


def pkola(r):
    return 3.1415 * r * r


def okola(r):
    return 3.1415 * r * 2


def ptrapezu(a, b, h):
    return (a + b) * h / 2


print("Co chcesz otrzymać?\n1. Pole figury\n2. Obwód figury\n3. Pole powierzchni bryły\n4. Objetość bryły")
choice = int(input("Podaj numer: "))
if 0 <= choice <= 4:
    if choice == 1:
        wynik = zapytaj_figura("pole powierzchni")
        if wynik == 1:
            a = zapytaj_zmienne(wynik)
            if a <= 0:
                print("Złe dane!")
            else:
                print("Pole kwadratu wynosi: " + str(pkwadrat(a)))
        if wynik == 2:
            a, b = zapytaj_zmienne(wynik)
            if a <= 0 or b <= 0:
                print("Złe dane!")
            else:
                print("Pole prostokąta wynosi: " + str(pprostokat(a, b)))
        if wynik == 3:
            a, h = zapytaj_zmienne(wynik)
            if a <= 0 or h <= 0:
                print("Złe dane!")
            else:
                print("Pole trójkąta wynosi: " + str(ptrojkat(a, h)))
        if wynik == 4:
            a = zapytaj_zmienne(wynik)
            if a <= 0:
                print("Złe dane!")
            else:
                print("Pole koła wynosi: " + str(pkola(a)))
        if wynik == 5:
            a, b, h = zapytaj_zmienne(wynik)
            if a <= 0 or b <= 0 or h <= 0:
                print("Złe dane!")
            else:
                print("Pole trapezu: " + str(ptrapezu(a, b, h)))
    if choice == 2:
        wynik = zapytaj_figura("obwód")
        if wynik == 1:
            a = zapytaj_zmienne(wynik)
            if a <= 0:
                print("Złe dane!")
            else:
                print("Obwód kwadratu wynosi: " + str(okwadrat(a)))
        if wynik == 2:
            a, b = zapytaj_zmienne(wynik)
            if a <= 0 or b <= 0:
                print("Złe dane!")
            else:
                print("Obwód prostokąta wynosi: " + str(oprostokat(a, b)))
        if wynik == 3:
            print("Błąd! Nie liczę obwodu trójkąta")
        if wynik == 4:
            a = zapytaj_zmienne(wynik)
            if a <= 0:
                print("Złe dane!")
            else:
                print("Obwód koła: " + str(okola(a)))
        if wynik == 5:
            print("Błąd! Nie liczę obwodu trapezu")
    if choice == 3:
        wynik = zapytaj_bryla("pole powierzchni")
        if wynik == 6:
            a = zapytaj_zmienne(wynik)
            if a <= 0:
                print("Złe dane!")
            else:
                print("Pole sześcianu wynosi: " + str(pkwadrat(a) * a))
        if wynik == 7:
            a, b = zapytaj_zmienne(wynik)
            if a <= 0 or b <= 0:
                print("Złe dane!")
            else:
                print("Pole prostopadłościanu wynosi: " + str(pkwadrat(a) * b))
        if wynik == 8:
            a, h = zapytaj_zmienne(wynik)
            if a <= 0 or h <= 0:
                print("Złe dane!")
            else:
                print("Pole stożka wynosi: " + str(pkola(a) * h / 3))
        if wynik == 9:
            a = zapytaj_zmienne(wynik)
            if a <= 0:
                print("Złe dane!")
            else:
                print("Pole walca wynosi: " + str(pkola(a) * h))
        if wynik == 10:
            r = zapytaj_zmienne(wynik)
            if r <= 0:
                print("Złe dane!")
            else:
                print("Pole kuli: " + str(4 * 3.1415 * r * r))
    if choice == 4:
        wynik = zapytaj_bryla("objętość")

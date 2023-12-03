# Projekt Strojnog Učenja s Neuronskim Mrežama

Projekt istražuje domenu strojnog učenja kroz implementaciju neuronskih mreža. Projekt se sastoji od dva ključna primjera.

---

## Primjer 1: Perceptron

Prvi primjer predstavlja perceptron, najjednostavniju neuronsku mrežu s jednim neuronom. Ova mreža omogućava prepoznavanje jednostavnih uzoraka, kao što su povezanosti između skupova brojeva. Prikazi prije i nakon procesa učenja jasno demonstriraju kako se model prilagođava tijekom vremena.

![image](https://github.com/AnteDev00/Machine-Learning/assets/151842550/260ce590-f998-469b-b528-65eb19529eeb)

Cilj je da Perceptron nauči poveznicu između prvog skupa (0,1,2,3,4,5) i drugog skupa (0,2,4,6,8,10), a to jest samo množenje sa brojem 2 (i dodavanje ničeg).


### Prije učenja:
![image](https://github.com/AnteDev00/Machine-Learning/assets/151842550/511af133-9098-453d-b4ae-da5d57db65c0)


Kao što vidimo, na početku model množi sa brojem 3.91 i dodaje vrijednost -0.14 .
Zbog toga su njegove predikcije krive.

### Nakon učenja:
![Nakon učenja](https://github.com/AnteDev00/Machine-Learning/assets/151842550/8ce682d9-60f9-4058-8b9b-f4fd6e7a3728)

Tokom procesa učenja, model smanjuje broj 3.91 -> 2, te vrijednost -0.14 -> 0.

To se postiglo zbog funkcije Cost, te je čitav cilj procesa učenja smanjiti vrijednost Cost funkcije, prilagođavajući parametre i poboljšavajući predikcije modela.

![image](https://github.com/AnteDev00/Machine-Learning/assets/151842550/4efabe17-a8fc-4376-8e7d-e4dee064392c)


---

## Primjer 2: Više Neurona za Inteligentniji Sustav

Drugi primjer obuhvaća povezivanje više neurona kako bi stvorio inteligentniji sustav. Ovaj model, s tri povezana neurona, pokazuju sposobnost prepoznavanja kompleksnijih uzoraka i pravila, poput tablica istine (Truth tables).

![image](https://github.com/AnteDev00/Machine-Learning/assets/151842550/eb2a5ee0-5712-46d7-8557-b2a5e39b590a)

![image](https://github.com/AnteDev00/Machine-Learning/assets/151842550/4eac1bea-4556-4c04-9f6e-3499b13a96b6)

Kao što vidimo na tablici, model mora točno predvidit koji je vrijednost izlaza (0/1), ako mu damo 2 ulaza (npr. 0 i 0).

### Prije učenja:
![Prije učenja](https://github.com/AnteDev00/Machine-Learning/assets/151842550/4494c54c-f61a-4a68-b043-b6fe0335bbd6)

### Nakon učenja:
![Nakon učenja](https://github.com/AnteDev00/Machine-Learning/assets/151842550/7a37a789-9743-4d13-9013-e914ae231e80)

Ovaj model kontrolira ukupno devet vrijednosti, a nakon procesa učenja, predikcije postaju sve preciznije.

--- 

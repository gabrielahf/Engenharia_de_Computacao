

irmao(X, Y) :- pai(Z, X), pai(Z, Y), X \= Y.
irmao(X, Y) :- mae(Z, X), mae(Z, Y), X \= Y.

casas_relacionadas(Z, Y) :- casa(W, Y), casa(X, Z), casados(X, W);casados(W, X), Z\=Y, W\=X.


descendentes(Y, X) :- pai(X, Y).
descendentes(Y, X) :- mae(X, Y).
descendentes(Y, X) :- pai(X, Z), descendentes(Y, Z).
descendentes(Y, X) :- mae(X, Z), descendentes(Y, Z).



casa(doran, house_martell).
casa(trystane, house_martell).
casa(oberyn, house_martell).
casa(sand_snakes, house_martell).
casa(elia, house_martell).
casa(olenna, house_tyrell).
casa(luthor, house_tyrell).
casa(mace, house_tyrell).
casa(loras, house_tyrell).
casa(margaery, house_tyrell).
casa(tywin, house_lannister).
casa(joanna, house_lannister).
casa(jaime, house_lannister).
casa(cersei, house_lannister).
casa(tyrion, house_lannister).
casa(ormund, house_baratheon).
casa(steffon, house_baratheon).
casa(robert, house_baratheon).
casa(stannis, house_baratheon).
casa(renly, house_baratheon).
casa(shireen, house_baratheon).
casa(joffrey, house_baratheon).
casa(myrcella, house_baratheon).
casa(tommen, house_baratheon).
casa(hoster, house_tully).
casa(lysa, house_tully).
casa(edmure, house_tully).
casa(catelyn, house_tully).
casa(jon, house_arryn).
casa(robin, house_arryn).
casa(rickard, house_stark).
casa(brandon1, house_stark).
casa(eddard, house_stark).
casa(benjen, house_stark).
casa(lyanna, house_stark).
casa(robb, house_stark).
casa(sansa, house_stark).
casa(arya, house_stark).
casa(rickon, house_stark).
casa(brandon2, house_stark).
casa(aegon_i, house_targaryen).
casa(maekar_i, house_targaryen).
casa(aegon_v, house_targaryen).
casa(maester_aemon, house_targaryen).
casa(jaehaerys_ii, house_targaryen).
casa(rhaelle, house_targaryen).
casa(aerys_ii, house_targaryen).
casa(rhaegar, house_targaryen).
casa(viserys, house_targaryen).
casa(jon_snow, house_targaryen).
casa(deanerys, house_targaryen).



local(doran, dorne).
local(trystane, dorne).
local(oberyn, dorne).
local(sand_snakes, dorne).
local(elia, dorne).
local(olenna, the_reach).
local(luthor, the_reach).
local(mace, the_reach).
local(loras, the_reach).
local(margaery, the_reach).
local(ormund, stormlands).
local(steffon, stormlands).
local(robert, stormlands).
local(stannis, stormlands).
local(renly, stormlands).
local(shireen, stormlands).
local(joffrey, stormlands).
local(myrcella, stormlands).
local(tommen, stormlands).
local(tywin, westerland).
local(joanna, westerland).
local(jaime, westerland).
local(cersei, westerland).
local(tyrion, westerland).
local(jon,the_vale).
local(robin, the_vale).
local(hoster, the_riverlands).
local(lysa, the_riverlands).
local(edmure, the_riverlands).
local(catelyn, the_riverlands).
local(rickard, the_north).
local(brandon1, the_north).
local(eddard, the_north).
local(benjen, the_north).
local(lyanna, the_north).
local(robb, the_north).
local(sansa, the_north).
local(arya, the_north).
local(rickon, the_north).
local(brandon2, the_north).


pai(jaehaerys_ii, aerys_ii).
pai(ormund, steffon).
pai(steffon, robert).
pai(steffon, stannis).
pai(steffon, renly).
pai(robert, joffrey).
pai(robert, myrcella).
pai(robert, tommen).
pai(stannis, shireen).
pai(doran, trystane).
pai(oberyn, sand_snakes).
pai(luthor, mace).
pai(mace, loras).
pai(mace, margaery).
pai(tywin, jaime).
pai(tywin, cersei).
pai(tywin, tyrion).
pai(jon, robin).
pai(hoster, edmure).
pai(hoster, lysa).
pai(hoster, catelyn).
pai(rickard, brandon1).
pai(rickard, eddard).
pai(rickard, benjen).
pai(rickard, lyanna).
pai(eddard, robb).
pai(eddard, sansa).
pai(eddard, arya).
pai(eddard, rickon).
pai(eddard, brandon2).
pai(aegon_i, maekar_i).
pai(maekar_i, maester_aemon).
pai(maekar_i, aegon_v).
pai(aegon_v, jaehaerys_ii).
pai(aegon_v, rhaelle).
pai(aerys_ii, rhaegar).
pai(aerys_ii, viserys).
pai(aerys_ii, deanerys).
pai(rhaegar, jon_snow).
pai(rhaegar, raenys).
pai(rhaegar, aegon).
pai(walder_frey, roslin_frey).
pai(roose_bolton, ramsay_bolton).
pai(balon_greyjoy, theon_greyjoy).
pai(jaime,tommen).
pai(jaime, joffrey).
pai(jaime, myrcella).




mae(elia, raenys).
mae(elia, aegon).
mae(olenna, mace).
mae(joanna, jaime).
mae(joanna, cersei).
mae(joanna, tyrion).
mae(cersei ,joffrey).
mae(cersei ,myrcella).
mae(cersei ,tommen).
mae(lysa, robin).
mae(catelyn, rickon).
mae(catelyn, brandon).
mae(catelyn, arya).
mae(catelyn, sansa).
mae(catelyn, robb).
mae(lyanna, jon_snow).
mae(rhaelle, steffon).


casados(elia, rhaegar).
casados(olenna, luthor).
casados(margaery, joffrey).
casados(margaery, tommen).
casados(margaery, renly).
casados(tywin, joanna).
casados(cersei, robert).
casados(ormund, rhaelle).
casados(edmure, roslin_frey).
casados(lysa, jon).
casados(lysa, little-finger).
casados(catelyn, eddard).
casados(sansa, ramsay_bolton).
casados(robb, talisa).
casados(rhaegar, lyanna).


% Regra (a)
vazio([]).

% Regra (b)
pertence([Y|_],Y).
pertence([_|Resto], Y) :- pertence(Resto, Y).

% Regra (c)
somatorio([],0).
somatorio([H|T],Soma) :- somatorio(T,Resto), Soma is H + Resto.

% Regra (d)
indice(X,Y,I) :- nth0(I, X, Y).

% Regra (e)
reverso([],[]).
reverso([H|T],Y) :- reverso(T,Resto), append(Resto,[H],Y).

% Exemplo de uso:
exemplo :-
    % Testando vazio
    vazio([]),
    write('([]) é vazia.\n'),

    % Testando pertence
    pertence([1,2,3,4],3),
    write('[1, 2, 3, 4] contém 3.\n'),

    % Testando somatorio
    somatorio([1,2,3,4],Soma),
    write('O somatório de [1, 2, 3, 4] é '), write(Soma), write('.\n'),

    % Testando indice
    indice([10,20,30,40],30,Indice),
    write('30 está no índice '), write(Indice), write(' de [10, 20, 30, 40].\n'),

    % Testando reverso
    reverso([0,1,2], ListaReversa),
    write('[0,1,2] invertida é '), write(ListaReversa), write('.\n').

% Executa o exemplo
:- exemplo.

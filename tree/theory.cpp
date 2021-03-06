Введение:

Для того чтобы граф T считался деревом, он должен следовать всем следующим ограничениям 
(которые могут быть доказаны как эквивалентные ограничения):

1)T соединен и не имеет неориентированных циклов (т. Е. Если бы направленные направленные ребра T не были направлены, циклов не было бы)

2)T является ациклическим, и образуется простой цикл, если к T добавляется любое ребро

3)T подключен, но не подключен, если какой-либо один край удален из T

4)Существует единственный простой путь, соединяющий любые две вершины из T

сли T имеет n вершин (где n - конечное число), то приведенные выше утверждения эквивалентны следующим двум условиям:

1. T связно и имеет n-1 ребра
2. T не имеет простых циклов и имеет n-1 ребра

---------------------------------------------------------------------------------------------------------------------------------------
  
Виды обходов

1,2,3- обходы в глубину.

1)При pre-order(префиксный) мы сначала посещаем текущий узел, затем мы рекурсируем на левом дочернем элементе (если он существует),
а затем мы рекурсируем на правый ребенок (если он существует). Проще говоря, VLR (Визит-Влево-Вправо).

2)В in-order(инфиксный) мы сначала рекурсируем на левом дочернем элементе (если таковой существует), то мы посещаем текущий узел, а затем
мы рекурсируем на правый ребенок (если он существует). Проще говоря, LVR (Left-Visit-Right).

3)В post-order(постфиксный) мы сначала рекурсируем на левом дочернем элементе (если он существует), то мы рекурсируем на нужном ребенке (если 
он существует), а затем мы посетим текущий узел. Проще говоря, LRV (Left-Right-Visit).

4)В обходе по уровням(обход в ширину), мы посещаем узлы поэтапно (где корень является «первым уровнем», его дети являются «вторым уровнем» и т. Д.), И на данном 
уровне мы посещаем узлы, направо.
  
----------------------------------------------------------------------------------------------------------------------------------------
  
HEAP(куча)
  
Куча - это дерево, которое удовлетворяет Свойству кучи: для всех узлов A и B, если узел A является родительским элементом узла B, 
то узел A имеет более высокий приоритет (или равный приоритет), чем узел B. В этом тексте мы будем обсуждают только двоичные кучи 
(т. е. кучи, которые являются бинарными деревьями), но это ограничение двоичного дерева не требуется от куч вообще. Бинарная куча 
имеет три ограничения:

1)Свойство двоичного дерева: все узлы в дереве должны иметь либо 0, 1, либо 2 ребенка

2)Свойство кучи (объяснено выше)

3)Свойство формы: куча - полное дерево. Другими словами, все уровни дерева, кроме, возможно, нижнего, полностью заполняются, и, если 
последний уровень дерева не завершен, узлы этого уровня заполняются слева направо

MIN-куча - это куча, где каждый узел меньше (или равен) всем своим детям (или не имеет детей). Другими словами, считается,
что узел A имеет более высокий приоритет, чем узел B, если A <B (то есть при сравнении двух узлов меньший из них имеет более 
высокий приоритет). 

MAX-куча - это куча, где каждый узел больше (или равен) всем своим детям (или не имеет детей). Другими словами, считается, что узел A 
имеет более высокий приоритет, чем узел B, если A> B (то есть, сравнивая два узла, более высокий из них имеет более высокий приоритет).
  
Визуализация-> https://www.cs.usfca.edu/~galles/visualization/Heap.html

----------------------------------------------------------------------------------------------------------------------------------------
  
Binary Search Tree

Бинарное дерево - это структура данных, дерево, у которого не более двух потомков для одного родителя.

Сбалансированное дерево - бинарное дерево, у которого глубина логарифмически зависит от кол-ва элементов. 

Идеально сбалансированное дерево - дерево, у которого все уровни заполнены, кроме последнего.  
  
Деревья поиском - те же бинарные деревья, только у левого поддерева потомки должны быть меньше значения родителя, 
а у правого больше либо равно.

Визуализация-> https://www.cs.usfca.edu/~galles/visualization/BST.html


  
  

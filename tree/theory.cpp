Введение:

Для того чтобы граф T считался деревом, он должен следовать всем следующим ограничениям 
(которые могут быть доказаны как эквивалентные ограничения):

T соединен и не имеет неориентированных циклов (т. Е. Если бы направленные направленные ребра T не были направлены, циклов не было бы)
T является ациклическим, и образуется простой цикл, если к T добавляется любое ребро
T подключен, но не подключен, если какой-либо один край удален из T
Существует единственный простой путь, соединяющий любые две вершины из T
Если T имеет n вершин (где n - конечное число), то приведенные выше утверждения эквивалентны следующим двум условиям:

T связно и имеет n-1 ребра
T не имеет простых циклов и имеет n-1 ребра
Однако мы столкнулись с некоторой проблемой с графом 0-узла, который мы ранее называли «пустым» деревом. 
С одной стороны, в качестве графика он нарушает некоторые из перечисленных выше ограничений и поэтому не 
следует рассматривать как дерево. С другой стороны, мы явно называем это действительной структурой данных
дерева ранее, потому что она представляет собой структуру данных дерева, содержащую 0 элементов, которая 
действительна. Каков правильный вердикт? Для целей этого текста, поскольку мы сосредоточены на структурах 
данных, а не на алгоритмах графа, конкретно, давайте явно обработать этот случай края и просто скажем, что 
граф с 0-узлом является допустимым деревом, несмотря на то, что он не выполняет некоторые из выше условий.

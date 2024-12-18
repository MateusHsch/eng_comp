defmodule Exemplo do
  def maior_de_idade?(idade) do
    idade >= 18
  end

  def quadrado(x), do: x * x

  def menor(x, y) when x >= y do
    y
  end
  def menor(x, y) when y > x do
    x
  end

  def par?(n) do
    rem(n, 2) == 0
  end
  def tres_iguais(x, y, z) do
    x == y && x == z
  end
end

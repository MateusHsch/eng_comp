defmodule Expressoes do
  def tres_iguais(x, y, z) do
    x == y && x == z
  end
  def menor(x,y) do
    cond do
      x >= y -> y
      y > x -> x
    end
  end

  # 1:
  def quatro_iguais(w, x, y, z) do
    w == y && w == x && w == z
  end

  # 2:
  #def quantos_iguais(x, y, z) do
  #  cond do
  #    x == y && x == z -> 3
  #    x != y && x != z -> 0
  #    true -> 2
  #  end
  #end

  # 3:
  def todos_diferentes(n, m, p), do: n != m && n != p && m != p

  # 4: Devemos testar se y tabém é diferente de z

  # 5:
  def quantos_iguais(n, m, p) do
    cond do
      tres_iguais(n, m, p) -> 3
      todos_diferentes(n, m, p) -> 0
      true -> 2
    end
  end

  # 6:
  def elevado_dois(n), do: n * n

  # 7:
  def elevado_quatro(n), do: elevado_dois(elevado_dois(n))

  # 8:
  def palindromo?(palavra) do
    palavra == String.reverse(palavra)
  end

  # 9:
  def verfica_triangulo(x, y, z) do
    x+y > z && x+z > y && y+z > x
  end

  # 10:
  def sinal(n) do
    cond do
      n < 0 -> -1
      n == 0 -> 0
      n > 0 -> 1
    end
  end

  # 11:
  def menor_tres(x, y, z) do
    menor(menor(x,y),z)
  end
end

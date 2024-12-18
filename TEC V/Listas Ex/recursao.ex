defmodule Recursao do
  def vendas(n) when n >= 0 do
    case n do
      0 -> 33
      1 -> 22
      2 -> 18
      3 -> 0
      4 -> 66
      6 -> 72
      _ -> 22
    end
  end

  # 1:
  def maxi(n1, n2) do
    cond do
      n1 > n2 -> n1
      true -> n2
    end
  end

  #2:
  def maior_venda(n) when n == 0, do: maxi(0, vendas(0))
  def maior_venda(n), do: maxi(vendas(n), maior_venda(n-1))

  #3:
  def semana_max_vendas(n) do
    cond do
      maior_venda(n) == vendas(n) -> n
      true -> semana_max_vendas(n-1)
    end
  end

  #4:
  #def zero_vendas(n) do
  #  cond do
  #    n < 0 -> -1
  #    vendas(n) == 0 -> n
  #    true -> zero_vendas(n-1)
  #  end
  #end

  #5:
  def acha_semana(s, n) do
    cond do
      n < 0 -> -1
      s == vendas(n) -> n
      true -> acha_semana(s, n-1)
    end
  end

  #6:
  def zero_vendas(n), do: acha_semana(0, n)

  #7:
  def acha_semana(s, m, n) do
    cond do
      n < m -> -1
      s == vendas(n) -> n
      true -> acha_semana(s, m, n-1)
    end
  end

  #8:
  def produto_mn(m, n) when m == n, do: m
  def produto_mn(m, n), do: produto_mn(m, n-1) * n

  #9:
  def potencia(_, e) when e == 0, do: 1
  def potencia(b, _) when b == 0, do: 0
  def potencia(b, e), do: b * potencia(b, e-1)

  #10:
  def fib(n) when n == 0, do: 0
  def fib(n) when n == 1, do: 1
  def fib(n), do: fib(n-1) + fib(n-2)

end

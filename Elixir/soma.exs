defmodule Soma do
    def soma(x,y) do
        x+y
    end
end

list = [1,2,3,4,5]
resultado = Enum.reduce(list, 0, &Soma.soma/2)
IO.puts resultado
struct Stack(N):
buf:    Item[N]
idx:    Uint
mutex:  Semaphore   // взаимно изключване
items:  Semaphore   // брой елементи в стека
spaces: Semaphore   // брой свободни места

init(s: Stack(N)):
s.idx := 0
s.mutex  := Semaphore(1)
s.items  := Semaphore(0)
s.spaces := Semaphore(N)

push(s: Stack(N), x: Item):
wait(s.spaces)        // блокира ако стекът е пълен
wait(s.mutex)         // влиза в критична секция
s.buf[s.idx] := x
s.idx += 1
signal(s.mutex)
signal(s.items)       // уведомява pop/peek

pop(s: Stack(N)) -> Item:
wait(s.items)         // блокира ако стекът е празен
wait(s.mutex)
result := s.buf[s.idx - 1]
s.idx -= 1
signal(s.mutex)
signal(s.spaces)      // уведомява push
return result

peek(s: Stack(N)) -> Item:
wait(s.items)         // блокира ако стекът е празен
wait(s.mutex)
result := s.buf[s.idx - 1]
signal(s.mutex)
signal(s.items)       // ВАЖНО: връща обратно броя!
return result

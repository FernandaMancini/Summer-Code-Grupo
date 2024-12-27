-- **Registro de todas as consultas SQL realizadas para solucionar o mistério.**

-- **1. Verificar a descrição do crime ocorrido no local e horário fornecidos.**
SELECT description
  FROM crime_scene_reports
 WHERE year = 2020
   AND month = 7
   AND day = 28
   AND street = 'Chamberlin Street';

-- **2. Identificar testemunhas (possíveis cúmplices) a partir das entrevistas realizadas na data do crime.**
SELECT name, transcript
  FROM interviews
 WHERE year = 2020
   AND month = 7
   AND day = 28;

-- **3. Investigar o nome 'Eugene', presente em duas transcrições, para verificar duplicidades.**
SELECT name
  FROM people
 WHERE name = 'Eugene';
-- Foi identificado que existe apenas um Eugene na tabela "people".

-- **4. Identificar as testemunhas que mencionaram 'courthouse' nas transcrições, organizadas alfabeticamente.**
SELECT name, transcript
  FROM interviews
 WHERE year = 2020
   AND month = 7
   AND day = 28
   AND transcript LIKE '%courthouse%'
 ORDER BY name;
-- Testemunhas identificadas: Eugene, Raymond e Ruth.

-- **5. Investigação com base nas pistas fornecidas por Eugene.**
-- Verificar as transações de saque no caixa eletrônico da rua Fifer.
SELECT account_number, amount
  FROM atm_transactions
 WHERE year = 2020
   AND month = 7
   AND day = 28
   AND atm_location = 'Fifer Street'
   AND transaction_type = 'withdraw';

-- Identificar os nomes associados às contas que realizaram essas transações.
SELECT name, atm_transactions.amount
  FROM people
  JOIN bank_accounts
    ON people.id = bank_accounts.person_id
  JOIN atm_transactions
    ON bank_accounts.account_number = atm_transactions.account_number
 WHERE atm_transactions.year = 2020
   AND atm_transactions.month = 7
   AND atm_transactions.day = 28
   AND atm_transactions.atm_location = 'Fifer Street'
   AND atm_transactions.transaction_type = 'withdraw';

-- **6. Investigação com base nas pistas fornecidas por Raymond.**
-- Identificar o aeroporto em Fiftyville, origem do voo do ladrão.
SELECT abbreviation, full_name, city
  FROM airports
 WHERE city = 'Fiftyville';

-- Listar os voos partindo do aeroporto de Fiftyville no dia 29 de julho, ordenados por horário.
SELECT flights.id, full_name, city, flights.hour, flights.minute
  FROM airports
  JOIN flights
    ON airports.id = flights.destination_airport_id
 WHERE flights.origin_airport_id =
       (SELECT id
          FROM airports
         WHERE city = 'Fiftyville')
   AND flights.year = 2020
   AND flights.month = 7
   AND flights.day = 29
 ORDER BY flights.hour, flights.minute;
-- Primeiro voo identificado: 8h20 para o Aeroporto Heathrow, Londres (ID do voo: 36).

-- Listar os passageiros do voo de Londres (voo às 8h20), organizados por número de passaporte.
SELECT passengers.flight_id, name, passengers.passport_number, passengers.seat
  FROM people
  JOIN passengers
    ON people.passport_number = passengers.passport_number
  JOIN flights
    ON passengers.flight_id = flights.id
 WHERE flights.year = 2020
   AND flights.month = 7
   AND flights.day = 29
   AND flights.hour = 8
   AND flights.minute = 20
 ORDER BY passengers.passport_number;

-- Investigar os registros de chamadas para identificar quem comprou a passagem:
-- Verificar possíveis nomes de quem ligou, ordenados pela duração das chamadas.
SELECT name, phone_calls.duration
  FROM people
  JOIN phone_calls
    ON people.phone_number = phone_calls.caller
 WHERE phone_calls.year = 2020
   AND phone_calls.month = 7
   AND phone_calls.day = 28
   AND phone_calls.duration <= 60
 ORDER BY phone_calls.duration;

-- Verificar possíveis nomes de quem recebeu a ligação, também ordenados pela duração das chamadas.
SELECT name, phone_calls.duration
  FROM people
  JOIN phone_calls
    ON people.phone_number = phone_calls.receiver
 WHERE phone_calls.year = 2020
   AND phone_calls.month = 7
   AND phone_calls.day = 28
   AND phone_calls.duration <= 60
 ORDER BY phone_calls.duration;

-- **7. Investigação com base nas pistas fornecidas por Ruth.**
-- Verificar as placas dos carros que saíram do tribunal entre 10h15 e 10h25, e identificar os proprietários.
SELECT name, courthouse_security_logs.hour, courthouse_security_logs.minute
  FROM people
  JOIN courthouse_security_logs
    ON people.license_plate = courthouse_security_logs.license_plate
 WHERE courthouse_security_logs.year = 2020
   AND courthouse_security_logs.month = 7
   AND courthouse_security_logs.day = 28
   AND courthouse_security_logs.activity = 'exit'
   AND courthouse_security_logs.hour = 10
   AND courthouse_security_logs.minute BETWEEN 15 AND 25
 ORDER BY courthouse_security_logs.minute;

-- **Conclusões**
-- Ernest é o ladrão, pois aparece em todas as listas (passageiros, transações no caixa eletrônico, registros de chamadas e saída do tribunal).
-- Ernest fugiu para Londres no voo identificado.
-- Berthold é o cúmplice, responsável pela compra da passagem de fuga.

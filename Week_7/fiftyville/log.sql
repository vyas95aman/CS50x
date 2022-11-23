-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT description -- to find the crime report that matches the date provided
   FROM crime_scene_reports
   WHERE year = 2021 AND month = 7 AND day = 28 AND street = "Humphrey Street" AND description LIKE "%CS50%";

SELECT activity, license_plate, hour, minute -- see what information that the bakery security logs provide. Maybe a license plate around that time
    FROM bakery_security_logs
    WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 25; -- minutes is updated to 10:15am to 10:25am

SELECT name, transcript -- noticed there was a transcript table with date datatype
    FROM interviews
    WHERE year = 2021 AND month = 7 AND day = 28 AND transcript LIKE "%bakery%"; -- found 3 leads - 10 min bakery window, atm leggett st, less than 1 min call

SELECT account_number, transaction_type, amount, atm_location -- lets see what info i can get from this lead, maybe account number
    FROM atm_transactions
    WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street"; -- yields too many results, maybe can cross ref with something

SELECT caller, receiver, duration -- get info on all calls less than one min on date
    FROM phone_calls
    WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60;

SELECT * -- try to find person based off of license plate and phone number... and update query with bank acct list
    FROM people
    WHERE phone_number IN (
        SELECT caller
        FROM phone_calls
        WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60
    )
    AND license_plate IN(
        SELECT license_plate
        FROM bakery_security_logs
        WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 25
    )
    AND id IN(
        SELECT person_id -- who are the people who have taken money out on that day, add the person id to people search
            FROM bank_accounts
            WHERE account_number in (
                SELECT account_number
                FROM atm_transactions
                WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street")
    ); -- This results in only two people... diana and bruce... which one was the robber? now lets narrow who took flights! And cross ref again

SELECT * -- who are the people who have taken money out on that day, add the person id to people search
    FROM bank_accounts
    WHERE account_number in (
        SELECT account_number
        FROM atm_transactions
        WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street"
    );


SELECT * -- find the airport id for fiftyville then use as origin in flights
    FROM airports
    WHERE city = "Fiftyville";

SELECT * -- This is the FLIGHT that was taken by the robber, 8:20am 29Jul2021 origin = 8, destination = 4
    FROM flights
    WHERE origin_airport_id = (
        SELECT id
    FROM airports
    WHERE city = "Fiftyville"
    )
    AND year = 2021 AND month = 7 AND day = 29 -- 29Jul bc Raymond said earliest flight out tomorrow
    ORDER BY hour ASC, minute ASC
    LIMIT 1; -- set limit for the earliest after 10am

SELECT * -- locate where the robber escaped to
    FROM airports
    WHERE id = (
        SELECT destination_airport_id -- find the flights that left from Fiftyville
            FROM flights
            WHERE origin_airport_id = (
                SELECT id
                    FROM airports
                    WHERE city = "Fiftyville"
                    )
                    AND year = 2021 AND month = 7 AND day = 29
                    ORDER BY hour ASC, minute ASC
                    LIMIT  1); -- set limit for earliest flight
                    -- Culrpit escaped to NYC, LaGuardia Airport!

SELECT * -- list of passport #s of all people who were on the flight, now cross this with people and the license plate and bank #
    FROM passengers
    WHERE flight_id = (
        SELECT id
            FROM flights
            WHERE origin_airport_id = (
                SELECT id
                    FROM airports
                    WHERE city = "Fiftyville"
                    )
                    AND year = 2021 AND month = 7 AND day = 29
                    ORDER BY hour ASC, minute ASC
                    LIMIT  1);

SELECT * -- find the robber based on match between license plate, passport and bank
    FROM people
    WHERE phone_number IN (
        SELECT caller
        FROM phone_calls
        WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60
    )
    AND license_plate IN (
        SELECT license_plate
        FROM bakery_security_logs
        WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 25
    )
    AND id IN (
        SELECT person_id -- who are the people who have taken money out on that day, add the person id to people search
            FROM bank_accounts
            WHERE account_number in (
                SELECT account_number
                FROM atm_transactions
                WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street")
    )
    AND passport_number IN (
        SELECT passport_number
            FROM passengers
            WHERE flight_id = (
                SELECT id
                    FROM flights
                    WHERE origin_airport_id = (
                        SELECT id
                            FROM airports
                            WHERE city = "Fiftyville"
                            )
                            AND year = 2021 AND month = 7 AND day = 29
                            ORDER BY hour ASC, minute ASC
                            LIMIT  1)
    );
-- Robber is Bruce!

-- Now to get accomplice:

SELECT * -- get the phone number of accomplice
    FROM phone_calls
    WHERE caller = (
        SELECT phone_number
            FROM people
            WHERE name = "Bruce"
    )
    AND year = 2021 AND month = 7 AND day = 28 AND duration < 60;

SELECT * -- Get name of accomplice! Robin
    FROM people
    WHERE phone_number = (
        SELECT receiver
            FROM phone_calls
            WHERE caller = (
                SELECT phone_number
                    FROM people
                    WHERE name = "Bruce"
            )
            AND year = 2021 AND month = 7 AND day = 28 AND duration < 60
    );
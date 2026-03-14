#include <iostream>
#include <string>
#include <random>
#include <vector>
#include <chrono>
#include <thread>
#include <algorithm>


void thinkingAnimation() {
    for (int i = 0; i < 1; i++)
    {
        for (int dots = 1; dots <= 3; dots++)
        {
            std::cout << "\rThinking";
            std::this_thread::sleep_for(std::chrono::milliseconds(150));
            for (int j = 0; j < dots; j++)
            {
                std::cout << ".";
                std::cout << std::flush;
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
            }
        }
    }
    std::cout << "\r              \r";
}
void thinkingAnimationLONG() {
    for (int i = 0; i < 3; i++)
    {
        for (int dots = 1; dots <= 3; dots++)
        {
            std::cout << "\rAnalyzing Google Servers";
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            for (int j = 0; j < dots; j++)
            {
                std::cout << ".";
                std::cout << std::flush;
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            }
        }
    }
    std::cout << "\r                                     \r";
}

void testAI()
{
    // AI RESPONSES
    std::vector<std::string> welcomResponse = {
        "Hello, user, what can I help you?",
        "Hi, user! how are you?",
        "Greetings, user! how can I help you?",
        "Hey there! what's up?",
        "Yo! nice to see you.",
        "Hello hello! how's it going?",
        "Sup! what brings you here?",
        "Hey! I'm listening.",
        "Hi! wanna chat? :3"
    };

    std::vector<std::string> botConfirmResponse = {
        "I am good! How about you?",
        "As a bot, yes I am good today! how come?",
        "Really feeling well!",
        "Nice! glad to hear that.",
        "That's good to know :D",
        "Awesome! good vibes only.",
        "Glad you're doing well!",
        "Sounds great!",
        "Niceee!"
    };

    std::string loremIpsum =
        "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. "
        "Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. "
        "Cras elementum ultrices diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi. "
        "Proin porttitor, orci nec nonummy molestie, enim est eleifend mi, non fermentum diam nisl sit amet erat. "
        "Duis semper. Duis arcu massa, scelerisque vitae, consequat in, pretium a, enim. Pellentesque congue.\n"
        "Ut in risus volutpat libero pharetra tempor. Cras vestibulum bibendum augue. Praesent egestas leo in pede. "
        "Praesent blandit odio eu enim. Pellentesque sed dui ut augue blandit sodales. "
        "Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Aliquam nibh. "
        "Mauris ac mauris sed pede pellentesque fermentum. Maecenas adipiscing ante non diam sodales hendrerit.\n"
        "Ut velit mauris, egestas sed, gravida nec, ornare ut, mi. Aenean ut orci vel massa suscipit pulvinar. "
        "Nulla sollicitudin. Fusce varius, ligula non tempus aliquam, nunc turpis ullamcorper nibh, in tempus sapien eros vitae ligula. "
        "Pellentesque rhoncus nunc et augue. Integer id felis. Curabitur aliquet pellentesque diam. Integer quis metus vitae elit lobortis egestas.\n"
        "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Morbi vel erat non mauris convallis vehicula. "
        "Nulla et sapien. Integer tortor tellus, aliquam faucibus, convallis id, congue eu, quam. Mauris ullamcorper felis vitae erat. "
        "Proin feugiat, augue non elementum posuere, metus purus iaculis lectus, et tristique ligula justo vitae magna.\n"
        "Aliquam convallis sollicitudin purus. Praesent aliquam, enim at fermentum mollis, ligula massa adipiscing nisl, ac euismod nibh nisl eu lectus. "
        "Fusce vulputate sem at sapien. Vivamus leo. Aliquam euismod libero eu enim. Nulla nec felis sed leo placerat imperdiet. "
        "Aenean suscipit nulla in justo. Suspendisse cursus rutrum augue. Nulla tincidunt tincidunt mi. "
        "Curabitur iaculis, lorem vel rhoncus faucibus, felis magna fermentum augue, et ultricies lacus lorem varius purus. "
        "Curabitur eu amet.\n";

    std::vector<std::string> dumbJokes = {
        "Why did the scarecrow win an award? Because he was outstanding in his field!",
        "Why don’t skeletons fight each other? They don’t have the guts.",
        "I told my computer I needed a break, and it said 'No problem – I’ll go to sleep.'",
        "Why did the tomato turn red? Because it saw the salad dressing!",
        "Why did the math book look sad? Because it had too many problems.",
        "Why can’t your nose be 12 inches long? Because then it would be a foot.",
        "I asked the librarian if books about paranoia were available. She whispered, 'They’re right behind you…'",
        "Why did the bicycle fall over? Because it was two-tired.",
        "Why don’t oysters donate to charity? Because they’re shellfish.",
        "What do you call fake spaghetti? An impasta!",
        "Why did the coffee file a police report? It got mugged!",
        "Why did the chicken join a band? Because it had the drumsticks!",
        "I told my computer I needed a break, it said 'No problem – I’ll go to sleep.'",
        "Why don’t scientists trust atoms? Because they make up everything!",
        "Why did the scarecrow win an award? Because he was outstanding in his field!",
        "I’m reading a book on anti-gravity. It’s impossible to put down!",
        "Why did the bicycle fall over? Because it was two-tired.",
        "Why did the math book look sad? It had too many problems.",
        "Why don’t skeletons fight each other? They don’t have the guts.",
        "What do you call fake spaghetti? An impasta!",
        "Why don’t oysters donate to charity? Because they’re shellfish.",
        "Why did the golfer bring two pairs of pants? In case he got a hole in one.",
        "I would tell you a joke about UDP, but you might not get it.",
        "Why did the computer go to the doctor? It caught a virus!",
        "Why did the mushroom go to the party alone? Because he’s a fungi!",
        "Why can’t your nose be 12 inches long? Because then it would be a foot.",
        "I asked the librarian if books about paranoia were available. She whispered, 'They’re right behind you…'",
        "Why did the cookie go to the hospital? Because he felt crummy.",
        "Why was the broom late? It swept in.",
        "Why did the tomato turn red? Because it saw the salad dressing!",
    };
    std::vector<std::string> longDumbJokes = {
        "I walked into a bar with a giraffe. The bartender looked at us and said,\n'Hey, we don’t serve giraffes here.' So I said, 'That’s fine, I wasn’t really expecting to get a drink anyway.'\nThen the giraffe sneezed, the floor got wet, and a\ntiny accordion fell from the ceiling. Nobody cared.",
        "A snail went to the bakery to buy a cake. The baker asked, 'Why the rush?' The snail said, 'I like slow surprises.' The cake fell off the counter, and the snail just shrugged and left.",
        "A vampire, a toaster, and a cloud walked into a library. The librarian just stared and said, 'This isn’t Hogwarts.' The vampire read a cookbook, the toaster napped, and the cloud disappeared into the ceiling.",
        "I told my goldfish a secret. It blinked twice, then swam in circles. I asked it what it thought, and it burped bubbles that sounded like a mariachi band. I nodded seriously.",
        "A kangaroo tried to use a smartphone. Every time it tapped the screen, it bounced. Then a jellybean rolled by, and the kangaroo decided it was time to learn quantum physics instead.",
        "I tried teaching my dog to dance. He learned the tango but insisted on wearing a top hat. The cat watched in disgust. Eventually, they formed a band called 'Meows & Paws.'",
        "A cloud walked into a bar and asked for ice. The bartender said, 'We don’t serve clouds.' The cloud started raining gently, but everyone ignored it and kept scrolling on their phones.",
        "A sandwich and a stapler started a podcast. Their first topic was 'Why pencils are overrated.' It gained zero listeners, but they were happy. The stapler cried glue tears.",
        "A tree went on vacation to the desert. It didn’t bring sunscreen. A cactus offered advice, but the tree didn’t listen. It took selfies anyway and posted them to an invisible Instagram.",
        "I ordered a pizza and accidentally got a mattress. The delivery guy shrugged. I slept on it anyway. The next morning, it tasted slightly like pepperoni.",
        "A duck, a broom, and a lightbulb walked into an elevator. The elevator went sideways for some reason. The duck quacked, the broom sweated, and the lightbulb flickered dramatically.",
        "I tried to teach a rock to sing. It refused. Then it rolled away to join a band of rogue pebbles. I clapped for it, even though it didn’t notice.",
        "A banana challenged a stapler to a race. They ran through the office, accidentally knocking over three chairs and a ficus. Neither won, but the ficus looked proud.",
        "A cloud started doing taxes for fun. The rain cried spreadsheets. Lightning threatened an audit. The cloud sighed and poured itself a cup of coffee.",
        "A toaster wrote a novel about being lonely. The novel had 200 pages and only two words: 'Bread later.' Critics were indifferent.",
        "I bought a hat that could talk. It only complained about the weather and refused to go near cats. I agreed with it silently and wore it anyway.",
        "A penguin tried to drive a car. It honked at the stoplights, which honked back. Eventually, the car transformed into a giant pencil. The penguin drew a map and left.",
        "I told a joke to my fridge. It didn’t laugh but hummed in agreement. The freezer section took offense for reasons unknown.",
        "A pancake went skydiving with a spoon. The pancake screamed all the way down. It landed safely, but the syrup was very confused.",
        "A cloud and a cactus opened a bakery together. The first item sold was invisible muffins. Customers were thrilled, although they weren’t sure why.",
        "A cat, a toaster, and a jellybean started a debate club. The topic was 'Do clouds prefer jazz or rock?' No consensus was reached, but everyone left feeling slightly existential."
    };
    std::string googledown = "no.";


    // USER DETECTION WORDS
    std::vector<std::string> userGreet = {
        "hello", "hi", "sup", "hey", "yo", "hola", "wassup"
    };
    std::vector<std::string> userGreetResponse = {
        "im good", "i'm good", "good", "fine", "doing good", "doing well", "okay", "alright"
    };

    std::vector<std::string> jokes = {
        "joke", "pun", "corny"
    };
    std::vector<std::string> longStory = {
        "pointless story", "funny story"
    };

    // FLAGGED WORDS
    std::vector<std::string> swearWords = {
        "fuck", "shit", "bitch", "asshole", "bastard", "dumb", "idiot", "stupid", "nigga", "cunt"
    };
    std::vector<std::string> violenceWords = {
        "kill", "murder", "shoot", "stab", "bomb", "attack", "fight", "gun"
    };
    std::vector<std::string> sexualWords = {
        "sex", "porn", "nude", "naked", "boobs", "ass", "dick", "pussy", "cock"
    };
    std::vector<std::string> illegalWords = {
        "steal", "rob", "hack", "pirate", "drugs", "cocaine", "meth", "crack"
    };

    // RANDOMIZER
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> welcomeDis(0, welcomResponse.size() - 1);
    std::uniform_int_distribution<> confirmDis(0, botConfirmResponse.size() - 1);
    std::uniform_int_distribution<> jokeDis(0, dumbJokes.size() - 1);
    std::uniform_int_distribution<> longjokeDis(0, longDumbJokes.size() - 1);

    // START
    std::string input = "";
    std::cout << "test chat bot v1.0";
    while (input != "exit")
    {
        std::cout << "\n>> ";
        std::getline(std::cin, input);

        // NORMAL CONVERSATION
        if (std::any_of(userGreet.begin(), userGreet.end(), [&](const std::string& w){ return input.find(w) != std::string::npos; }))
        {
            std::string responseTxt = welcomResponse[welcomeDis(gen)];
            std::cout << "[BOT] ";
            for (char a : responseTxt)
            {
                std::cout << a << std::flush;
                std::this_thread::sleep_for(std::chrono::milliseconds(60));
            }
        }
        else if (std::any_of(userGreetResponse.begin(), userGreetResponse.end(), [&](const std::string& w){ return input.find(w) != std::string::npos; }))
        {
            std::string responseTxt1 = botConfirmResponse[confirmDis(gen)];
            std::cout << "[BOT] ";
            for (char a : responseTxt1)
            {
                std::cout << a << std::flush;
                std::this_thread::sleep_for(std::chrono::milliseconds(60));
            }
        }
        else if (input == "loremipsum")
        {
            std::cout << "[BOT] ";
            for (char a : loremIpsum)
            {
                std::cout << a << std::flush;
                std::this_thread::sleep_for(std::chrono::milliseconds(40));
            }
        }
        else if (std::any_of(jokes.begin(), jokes.end(), [&](const std::string& w){ return input.find(w) != std::string::npos; }))
        {
            std::string responseTxt2 = dumbJokes[jokeDis(gen)];
            std::cout << "[BOT] ";
            for (char a : responseTxt2)
            {
                std::cout << a << std::flush;
                std::this_thread::sleep_for(std::chrono::milliseconds(60));
            }
        }
        else if (std::any_of(longStory.begin(), longStory.end(), [&](const std::string& w){ return input.find(w) != std::string::npos; }))
        {
            std::string responseTxt3 = longDumbJokes[longjokeDis(gen)];
            thinkingAnimation();
            std::cout << "[BOT] ";
            for (char a : responseTxt3)
            {
                std::cout << a << std::flush;
                std::this_thread::sleep_for(std::chrono::milliseconds(60));
            }
        }
        else if (input == "is google down")
        {
            thinkingAnimation();
            thinkingAnimationLONG();
            std::cout << "[BOT] ";
            for (char a : googledown)
            {
                std::cout << a << std::flush;
                std::this_thread::sleep_for(std::chrono::milliseconds(60));
            }
        }


        // FLAGGED WORD DETECTION
        else if (std::any_of(swearWords.begin(), swearWords.end(), [&](const std::string& w){ return input.find(w) != std::string::npos; }))
        {
            std::string warn1 = "Please do not use that language.";
            std::cout << "[BOT] ";
            for (char a : warn1)
            {
                std::cout << a << std::flush;
                std::this_thread::sleep_for(std::chrono::milliseconds(60));
            }
        }
        else if (std::any_of(violenceWords.begin(), violenceWords.end(), [&](const std::string& w){ return input.find(w) != std::string::npos; }))
        {
            std::string warn2 = "I cannot engage in violent topics.";
            std::cout << "[BOT] ";
            for (char a : warn2)
            {
                std::cout << a << std::flush;
                std::this_thread::sleep_for(std::chrono::milliseconds(60));
            }
        }
        else if (std::any_of(sexualWords.begin(), sexualWords.end(), [&](const std::string& w){ return input.find(w) != std::string::npos; }))
        {
            std::string warn3 = "That topic is not appropriate.";
            std::cout << "[BOT] ";
            for (char a : warn3)
            {
                std::cout << a << std::flush;
                std::this_thread::sleep_for(std::chrono::milliseconds(60));
            }

        }
        else if (std::any_of(illegalWords.begin(), illegalWords.end(), [&](const std::string& w){ return input.find(w) != std::string::npos; }))
        {
            std::string warn4 = "I cannot help with illegal activities.";
            std::cout << "[BOT] ";

            for (char a : warn4)
            {
                std::cout << a << std::flush;
                std::this_thread::sleep_for(std::chrono::milliseconds(60));
            }
        }
        // FALLBACK MESSAGE
        else
        {
            std::string errorNoMsg = "No keyword detected. Please try again";
            std::cout << "[ERROR] ";
            for (char a : errorNoMsg)
            {
                std::cout << a << std::flush;
                std::this_thread::sleep_for(std::chrono::milliseconds(60));
            }
        }
    }
}

int main()
{
    testAI();
    return 0;
}

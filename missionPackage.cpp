#include "missionPackage.h"

MissionPackage::MissionPackage() {
    pacakge = new Mission * [50];
    // Create 50 mission one by one
    // mission 1
    pacakge[0] = new Mission(
        1,
        "Congratulations! You have been selected from a variety of applicants to take part in the most exciting, greatest and most dangerous adventure of mankind: the search for the unknown 9th planet. As soon as you arrive at the training ground for the final tests, you'll be sitting in your first training phase: Team building.",
        1,
        0,
        NULL,
        0,
        NULL
    );
    // mission 2
    pacakge[1] = new Mission(
        2,
        "It quickly turns out that you are perfectly coordinated with each other. Above all, your mental connection, the so-called drift compatibility, speaks for a successful cooperation. Now face the training phases 2 and 3: control technique and weightlessness.",
        2,
        0,
        NULL,
        0,
        NULL
    );
    // mision 3
    int* array2 = new int[2];
    array2[0] = 1;
    array2[1] = 2;
    pacakge[2] = new Mission(
        3,
        "The training phases follow in quick succession. The combined Energy Supply and Emergency Prioritization course requires a high degree of logical thinking in order to understand and apply the links. Your mathematical background comes in handy here.",
        2,
        2,
        array2,
        0,
        NULL
    );
    // mission 4
    pacakge[3] = new Mission(
        4,
        "You are nearing completion of the preparations. The last training phases are the recalibration of the control modules, the reorientation of the communicators and the advanced auxiliary systems of the spacesuits. Nothing stands in the way of a quick start.",
        3,
        0,
        NULL,
        0,
        NULL
    );

    // mission 5
    std::string* s4 = new std::string[1];
    s4[0] = "No Trick";
    //  std::string s4[1] = {"No Trick"};
    pacakge[4] = new Mission(
        5,
        "Celebrated too soon! One of you is sick and stuck in bed. After everyone has looked at his, hand cards your Commander asks everyone about his or her condition. But you may only answer with \"Good\" or \"Bad\". Your Commander then decides who is ill. The sick crew member may not win a single trick.",
        0,
        0,
        NULL,
        1,
        s4
    );
    // mission 6
    int* array5 = new int[2];
    array5[0] = 0;
    array5[1] = 0;
    //  std::string s5[1] = {"Dead Spot"};
    std::string* s5 = new std::string[1];
    s5[0] = "Dead Spot";
    pacakge[5] = new Mission(
        6,
        "After this minor setback, your final training phase is about to begin: understanding with restricted communication. For this purpose, a reception dead spot is simulated, which can lead to a variety of circumstances in space. Strengthen your mental connection and pass the final tests.",
        3,
        2,
        array5,
        1,
        s5
    );
    // mission 7
    int* array6 = new int[1];
    array6[0] = 100;
    pacakge[6] = new Mission(
        7,
        "A memorable day! Get ready for takeoff. 10-9-8-7-6-5-4-3-2-1- LIFT OFF! The completion of your training is just the beginning of your adventure. A mighty force presses you into your seats – now there's no turning back. Under ear-splitting noise you leave the ground, the country, the continent, the planet.",
        3,
        1,
        array6,
        0,
        NULL
    );
    // mission 8
    int* array7 = new int[3];
    array7[0] = 1;
    array7[1] = 2;
    array7[2] = 3;
    //  int array7[3] = {1,2,3};
    pacakge[7] = new Mission(
        8,
        "You have reached lunar orbit, weightlessness sets in - an indescribable feeling. Numerous tests and trainings and yet the joy overwhelms you every time anew. You look back to the Earth, which was your entire cosmos so far and you can already cover it with your thumb.",
        3,
        3,
        array7,
        0,
        NULL
    );
    // mission 9
    std::string* s8 = new std::string[1];
    s8[0] = "1 Trick";
    //  std::string s8[1] = {"1 Trick"};
    pacakge[8] = new Mission(
        9,
        "You are suddenly torn from your thoughts when the on- board analysis module NAVI interrupts and demands your attention. In the drive electronics, a very small piece of metal has become jammed. To avoid damaging the boards, steady hands are required. A 1-value card must win a trick.",
        0,
        0,
        NULL,
        1,
        s8
    );
    // mission 10
    pacakge[9] = new Mission(
        10,
        "After this little excitement right at the beginning of your mission, you are now ready to leave the moon behind. You send your status to Earth, start all control and measuring instruments, and ignite the engines. This will truly be a big step. For you and for mankind.",
        4,
        0,
        NULL,
        0,
        NULL
    );

    //11
    int* array10 = new int[1];
    array10[0] = 1;
    // int array10[1] = {1};
    std::string* s10 = new std::string[1];
    s10[0] = "Cannot Communicate";
    // std::string s10[1] = {"Cannot Communicate"};
    pacakge[10] = new Mission(11,
        "Your radar systems report a dense meteorite field that will soon intercept your course. The Commander appoints another crew member to take care of the recalculation of the course. The task demands the highest concentration, so the particular crew member cannot communicate in this mission.",
        4,
        1,
        array10,
        1,
        s10);

    //12

    // std::string s11[1] = {"Draw Right"};
    std::string* s11 = new std::string[1];
    s11[0] = "Draw Right";
    pacakge[11] = new Mission(12,
        "You watch tensely, as you pass relatively close to the meteorites. In the excitement you mess up your paperwork, which causes a few minutes of strenuous confusion.Immediately after the 1st trick, each of you must draw a random card from the crew member to your right. Then continue playing normally.",
        4,
        1,
        array6,
        1,
        s11);


    //13
    // std::string s12[1] = {"Rocket"};
    std::string* s12 = new std::string[1];
    s12[0] = "Rocket";
    pacakge[12] = new Mission(13,
        "Apparently you were hit by smaller chunks despite course change. At any rate the control module shows a malfunction on the drive. Perform a thrust test on all drives to further pinpoint the problem. You must win a trick with each Rocket card.",
        0,
        0,
        NULL,
        1,
        s12);

    // int array13[3] = {0,0,0};
    int* array13 = new int[3];
    array13[0] = 0;
    array13[1] = 0;
    array13[2] = 0;
    // std::string s13[1] = {"Dead Spot"};
    // std::string* s13 = new std::string[1];
    // s13[0] = "Dead Spot";
    //14
    pacakge[13] = new Mission(14,
        "You are already close enough to Mars to be able to see Olympus Mons, the highest volcano in our solar system, with the naked eye. You take the opportunity to photograph it first and then the Martian moons Phobos and Deimos. The sight helps you get over the reception dead spot which you're currently stuck in.",
        4,
        3,
        array13,
        1,
        s5);

    // int array14[4] = {1,2,3,4};
    int* array14 = new int[4];
    array14[0] = 1;
    array14[1] = 2;
    array14[2] = 3;
    array14[3] = 4;
    //15
    pacakge[14] = new Mission(15,
        "You pass Mars and leave the reception dead spot. Your thoughts turn to chocolate bars when suddenly your collision module sounds the alarm. Even before you can react properly, you are hit by a meteorite. Immediately seal off the four damaged modules and begin the repair process.",
        4,
        4,
        array14,
        0,
        NULL);


    // std::string s15[1] = {"9 No Trick"};
    std::string* s15 = new std::string[1];
    s15[0] = "9 No Trick";
    //16
    pacakge[15] = new Mission(16,
        "Overall, the shock was more severe than the damage, and you were able to  most of it in time. However, the 9th Control Module, which monitors the life support systems of your suits, has been severely damaged in the collision and has failed. You cannot win a trick with a 9-value card.",
        0,
        0,
        NULL,
        1,
        s15);

    // std::string s16[1] = {"9 No Trick"};
    //17
    pacakge[16] = new Mission(17,
        "The damage on the 9th control module is even greater than originally thought, so you have to invest significantly more time in the repair. At the same time, however, you must keep an eye on your course and send a message to Earth, where your status is eagerly awaited. You are still not allowed to win a trick with a 9-value card.",
        2,
        0,
        NULL,
        1,
        s15);

    // std::string s17[1] = {"2 Comm"};
    std::string* s17 = new std::string[1];
    s17[0] = "2 Comm";
    //18
    pacakge[17] = new Mission(18,
        "You set course for Jupiter as you fly into a cloud of dust. Almost at the same moment your communication module reacts. At first it shows an amazingly good connection, but only seconds later it seems to have a total failure. You are only allowed to communicate starting with the 2nd trick.",
        5,
        0,
        NULL,
        1,
        s17);

    // int array18[1] = {1};
    // std::string s18[1] = {"3 Comm"};
    std::string* s18 = new std::string[1];
    s18[0] = "3 Comm";
    //19
    pacakge[18] = new Mission(19,
        "The dust cloud reveals extraordinary dimensions and the longer you are in it, the stranger your communication module reacts. It fluctuates between crystal clear and completely incomprehensible. However, the severely impaired periods become longer. You may not communicate until the start of the 3rd trick.",
        5,
        1,
        array10,
        1,
        s18);

    // std::string s19[1] = {"Order"};
    std::string* s19 = new std::string[1];
    s19[0] = "Order";
    //20
    pacakge[19] = new Mission(20,
        "Finally, the cloud clears and the deflections of the communication module are noticeably reduced. Before you, Jupiter presents itself in all its glory. The giant gas giant rightly bears its name. Your awe is interrupted as you notice the two damaged radar sensors. Your Commander determines who receives the orders and carries out the repair.",
        2,
        0,
        NULL,
        1,
        s19);

    // int array20[2] = {1,2};
    // std::string s20[1] = {"Dead Spot"};
    //21
    pacakge[20] = new Mission(21,
        "After the repair you will notice that the cloud has brought you too close to Jupiter. Its approx. 2.5-fold gravity already influences your course. To counteract it, you have to work in a concentrated and precise manner to get to the ideal exit point. You hardly notice the reception dead spot.",
        5,
        2,
        array2,
        1,
        s5);

    // int array21[4] = {0,0,0,0};
    int* array21 = new int[4];
    array21[0] = 0;
    array21[1] = 0;
    array21[2] = 0;
    array21[3] = 0;
    //22
    pacakge[21] = new Mission(22,
        "When you're out of the woods, the temperature suddenly drops noticeably. All control systems sound the alarm and you immediately put on your suits. The regulation module barely adapts to the adjustment. Reroute the power supply to other modules one by one to avoid a total system failure.",
        5,
        4,
        array21,
        0,
        NULL);

    // int array22[5] = {1,2,3,4,5};
    int* array22 = new int[5];
    array22[0] = 1;
    array22[1] = 2;
    array22[2] = 3;
    array22[3] = 4;
    array22[4] = 5;
    // std::string s22[1] = {"Change"};
    std::string* s22 = new std::string[1];
    s22[0] = "Change";
    //23
    pacakge[22] = new Mission(23,
        "Most of the modules are still on emergency power while you are discussing the cause of the rapid cooling. When you pass Callisto, one of the 69 Jupiter moons, you seem to have escaped the frost field. At least the readings have relativized. Reactivate the modules on standby. Before you select the Order cards, you may change the position of two Order tiles.",
        5,
        5,
        array22,
        1,
        s22);

    // std::string s23[1] = {"Order"};
    //24
    pacakge[23] = new Mission(24,
        "The unexpected incident has messed up your operationsquite a bit. Everywhere there is now something to do and for a moment, each of you uncontrollably wants to begin at some point. Your Commander takes the initiative and draws up a plan. In order to be able to proceed in a structured way, he distributes the individual orders.",
        6,
        0,
        NULL,
        1,
        s19);

    // int array24[2] = {0,0};
    // std::string s24[1] = {"Dead Spot"};
    //25
    pacakge[24] = new Mission(25,
        "You reach Saturn and pause to admire the grandiose spectacle of the rock tracks that continuously orbit it. It is called the ring planet for a reason. Almost apathetically, you devote yourself to the on-board analysis and sink into astonishment. Because of the reception dead spot you arehardly disturbed. If you are playing with five, you can now use the additional rule for 5 crew members.",
        6,
        2,
        array5,
        1,
        s5);

    // std::string s25[1] = {"1 Trick 2"};
    std::string* s25 = new std::string[1];
    s25[0] = "1 Trick 2";
    //26
    pacakge[25] = new Mission(26,
        "A loud bang breaks you out of the devout mood. Two pieces of rock around Saturn have torn holes into your ship's hull. The on-board analysis has immediately sealed off the affected storage area. Both stones are still stuck in the hull. You must carefully remove them without increasing the damage. Two 1-value cards must win one trick each.",
        0,
        0,
        NULL,
        1,
        s25);

    // std::string s26[1] = {"Order"};
    //27
    pacakge[26] = new Mission(27,
        "You notice that the tear of the hull has has leftconsequences. An inspection of the modules connected to the storage room shows that the flux compensator has been damaged. Although there is currently no problem, a repair is necessary in the long run if you want to return home. Your commander decides who will do the repair.",
        3,
        0,
        NULL,
        1,
        s19);

    // int array27[2] = {1,100};
    int* array27 = new int[2];
    array27[0] = 1;
    array27[1] = 100;
    // std::string s27[1] = {"3 Comm"};
    //28
    pacakge[27] = new Mission(28,
        "You measure an unusually high level of cosmic radiation. Seemingly unaffected, you continue your flight, only to find that your radio messages either do not arrive at all, or are very time-delayed at the receiver. It is not possible to work smoothly. You may not communicate until the start of the 3rd trick.",
        6,
        2,
        array27,
        1,
        s18);

    // std::string s28[2] = {"Dead Spot", "Balance"};
    std::string* s28 = new std::string[2];
    s28[0] = "Dead Spot";
    s28[1] = "Balance";
    //29
    pacakge[28] = new Mission(29,
        "Your communication module seems to have suffered more damage than you initially thought. The repair requires a series of tests and calibrations, which you must perform together and in precise coordination. At no time may a crew member have won 2 tricks more than another crew member. Communication is disrupted.",
        0,
        0,
        NULL,
        2,
        s28);

    // int array29[3] = {0,0,0};
    // std::string s29[1] = {"2 Comm"};
    //30
    pacakge[29] = new Mission(30,
        "One part is done, but you postpone the rest of the repair, as you are heading straight for Uranus. Its smooth, pale blue surface makes it look almost artificial. You tear yourselves away from this fascinating sight, because not all the damage has been repaired yet. You are only allowed to communicate starting from the 2nd trick.",
        6,
        3,
        array13,
        1,
        s17);

    //31
    // int array30[3] = {1,2,3};
    pacakge[30] = new Mission(31,
        "As you slowly move away from Uranus, you receive a message from Earth requesting the collection of metadata of the Uranus moons. Due to the disruption it's too late, so you can only see three of the 27 moons – Rosalind, Belinda and Puck. That'll have to do for now.",
        6,
        3,
        array7,
        0,
        NULL);

    //32
    // std::string s31[1] = {"Order"};
    pacakge[31] = new Mission(32, "Despite the good conditions, it is now noticeable how long you have been travelling together and how all too human characteristics come to light. In order to avoid a heated confrontation, everyone delves into their work. Your Commander takes over the organization and distributes the individual orders.",
        7,
        0,
        NULL,
        1,
        s19);

    //33
    // std::string s32[1] = {"Exactly One Trick"};
    std::string* s32 = new std::string[1];
    s32[0] = "Exactly One Trick";
    pacakge[32] = new Mission(33, "We got a field assignment coming up! One of the hatches is defective and must be repaired. But leaving the ship is always a risk. After everyone has looked at their hand of cards, your Commander asks everyone for their willingness. But you can only answer with 'Yes' or 'No'. Your Commander then selects a crew member. The selected crew member must win exactly 1 trick, but not with a Rocket card.",
        0,
        0,
        NULL,
        1,
        s32);

    // 34
    // std::string s33[2] = {"First Last Trick C","Balance"};
    std::string* s33 = new std::string[2];
    s33[0] = "First Last Trick C";
    s33[1] = "Balance";
    pacakge[33] = new Mission(34, "Neptune is already in sight when your ship begins to shake. Man the stabilizers so you don't lose control. In the meantime, your Commander must realign the gravity module. At no time may a crew member have won 2 tricks more than another crew member. Your Commander must win the first and last trick.",
        0,
        0,
        NULL,
        2,
        s33);

    // 35
    // int array34[3] = {0,0,0};
    pacakge[34] = new Mission(35, "Devoutly you reach the outermost planet of our solar system: the ice giant Neptune. Its deep blue makes you shiver. As you slowly pass Neptune, you receive another message from Earth. The spacecraft Alpha 5 orbits Neptune, but has damaged sensors. Locate and repair them.",
        7,
        3,
        array13,
        0,
        NULL);

    // 36
    // int array35[2] = {1,2};
    // std::string s35[1] = {"Order"};
    pacakge[35] = new Mission(36, "You use one of the rare calm moments to find out more about each other. With all the minor and major emergencies, the responsibility on your shoulders, and the uncertainty of the outcome of your adventure, the tension has crept to the core of each individual. It's good to just sit together, talk and listen. Relieved of a burden, you then dedicate yourself to the challenges ahead. Your Commander distributes the individual orders.",
        7,
        2,
        array2,
        1,
        s19);

    // 37
    // std::string s36[1] = {"Order"};
    pacakge[36] = new Mission(37, "You reach the dwarf planet Pluto. Many years ago it would have been the 9th planet. You indulge in memories of things your fathers used to explain to you on Sundays and think about changeability. Nevertheless, the ship must be kept on course. The Commander decides who takes care of it.",
        4,
        0,
        NULL,
        1,
        s19);

    //38
    // std::string s37[1] = {"3 Comm"};
    pacakge[37] = new Mission(38, "You reach the heliopause, the edge of our solar system. If the calculations prove to be true, the 9th planet can't be far. An intense tingling is spreading, the hour of truth is approaching. As your instruments bounce, you almost jump off your seats. But unfortunately it is only a disruption. You are only allowed to communicate starting from the 3rd trick.",
        8,
        0,
        NULL,
        1,
        s18);

    //39
    // int array38[3] = {0,0,0};
    // std::string s38[1] = {"Dead Spot"};
    pacakge[38] = new Mission(39, "That must be it! The displayed readings of your modules can only be generated by really gigantic objects. The effects are so massive that even your radio signal is interrupted. Recalibrate your instruments and find out what's really behind it.",
        8,
        3,
        array13,
        1,
        s5);

    //40
    // int array39[3] = {1,2,3};
    // std::string s39[1] = {"Remove One Order"};
    std::string* s39 = new std::string[1];
    s39[0] = "Remove One Order";
    pacakge[39] = new Mission(40, "You are now looking closely at the object, but you are still uncertain. What appears in front of you could also be a Pluto moon. No, that's not a moon! You have found it! The 9th planet! Boundless euphoria spreads within you and makes you forget all the hardships. The surface scan of the planet suggests a solid crust. That would mean that it is not another gas giant, but walkable. A fantastic opportunity opens up. Before you start choosing the Order cards, you may place an Order tile on another order without an Order tile.",
        8,
        3,
        array7,
        1,
        s39);

    //41

    // std::string s40[1] = {"First Last Trick"};
    std::string* s40 = new std::string[1];
    s40[0] = "First Last Trick";
    pacakge[40] = new Mission(41, "You adjust the engines and prepare for landing. Due to the completely new conditions, one of you will have to coordinate the landing. After everyone has looked at their hand of cards, your Commander will ask everyone for their willingness. However, you may only answer \"Yes\" or \"No\". Your Commander then selects a person. Your mission is that this person only wins the first and last trick. Since only the thrusters are used for position correction, both tricks may not be won with Rocket cards. 40 41 8 X Only 1st and L",
        0,
        0,
        NULL,
        1,
        s40);

    //42
    pacakge[41] = new Mission(42, "The planet is extremely cold and inhospitable, but seems habitable. You notice an area that seems to elude your instruments. The closer you get to this anomaly, the more glaring the measurement errors become. What presents itself to you transcends your knowledge of science. At least you can roughly narrow down the phenomenon, because the results normalize when you move away.",
        9,
        0,
        NULL,
        0,
        NULL);

    //43
    // std::string s42[1] = {"Order"};
    pacakge[42] = new Mission(43, "In the name of science, you venture closer. The laws of gravitation seem to reverse the closer you get to the anomaly and you anchor yourself to the planet's surface with vibranium hooks for safety. Your Commander secures the rest of the crew and distributes the individual orders. The results allow only one conclusion: You have discovered a wormhole.",
        9,
        0,
        NULL,
        1,
        s19);

    //44
    // std::string s43[1] = {"Rocket By Order"};
    std::string* s43 = new std::string[1];
    s43[0] = "Rocket By Order";
    pacakge[43] = new Mission(44, "Until now, wormholes were at best theoretical constructs and now you are here, right in front of it. It overshadows you like a black monolith - incomprehensible, but with a enormous gravitational pull. You send a message to Earth and prepare the engines for the jump. Each Rocket card must win a trick. First the 1-Rocket, then the 2, the 3 and finally the 4.",
        0,
        0,
        NULL,
        1,
        s43);

    //45
    // int array44[3] = {0,0,0};
    pacakge[44] = new Mission(45, "The impact is massive! You are strapped into your seats and feel like you're everywhere at the same time. Colors and shapes change, light feels like a swirling mass that behaves like an intelligent being and envelops you. You focus on your displays and try not to lose your mind",
        9,
        3,
        array13,
        0,
        NULL);

    //46
    // std::string s45[1] = {"Pink 9"};
    std::string* s45 = new std::string[1];
    s45[0] = "Pink 9";
    pacakge[45] = new Mission(46, "While you are faced with an incredible number of sensations, you still react instinctively to sources of danger. When all the main modules of the ship suddenly shut down during the jump, the red warning lights tear you out of your trance-like state. Your mission is for the crew member to the left of the one with the pink 9 to win all the pink cards. Declare who owns the pink 9.",
        0,
        0,
        NULL,
        1,
        s45);

    //47
    pacakge[46] = new Mission(47, "You are at the end of your rope. The jump now feels like a prison in which you can no longer distinguish between reality and imagination. Your body screams that you can barely stand 10 seconds longer, but your mind questions how long 10 seconds are in actuality. You count them down – and suddenly burst out of the wormhole.",
        10,
        0,
        NULL,
        0,
        NULL);

    //48
    // int array47[1] = {100};
    pacakge[47] = new Mission(48, "You hardly have time to orient yourself. All at once it is extremely hot everywhere. The on-board analysis immediately puts the entire ship at the highest risk level. The first modules fall victim to the radical temperature fluctuation. Even in your regulated suits, you will break out into sweats within seconds. You need to activate the emergency protocol, extend the heat shields and build up a greater distance to the heat source as quickly as possible. The last order must be won in the last trick.",
        3,
        1,
        array6,
        0,
        NULL);

    // int array48[3] = {0,0,0};
    pacakge[48] = new Mission(49, "When you come to your senses, the situation has returned to normal. You were barely able to take the necessary steps before you collapsed from exhaustion. You locate your location and can hardly believe it. You are in orbit of Venus! The wormhole is a direct link between the 9th planet and Venus, the 2nd planet. This also explains the extreme heat, because Venus is much closer to the sun than Earth. It takes a moment until it dawns on you: You can go home! Check all 10 main modules, but pay special attention to life support, drive and communication. Set course for Earth.",
        10,
        3,
        array13,
        0,
        NULL);

    // std::string s49[2] = {"First To Fourth Trick", "Last Trick"};
    std::string* s49 = new std::string[2];
    s49[0] = "First To Fourth Trick";
    s49[1] = "Last Trick";
    pacakge[49] = new Mission(50, "The way back is much more complicated than expected. Some modules are permanently damaged and you fight against the immense gravitational pull of the sun. With your last reserves, you can no longer afford to make a mistake under these conditions – the way home must be precisely timed. You must first use the gravity deflection to create the jump. After that, the ship modules must be kept under control and the approach to Earth initiated. In the end, landing on Earth requires no less attention than any other maneuver. Everyone looks at their hand of cards. A crew member must win the first 4 tricks. Another crew member must win the last trick. The remaining crew members must win all tricks in between. Your Commander asks everyone for his preferred task, then you decide together as a crew who should take over which position. But don't tell them anything about your hand of cards.",
        0,
        0,
        NULL,
        2,
        s49);
}

Mission** MissionPackage::get_mission_package() {
    return pacakge;
}

MissionPackage::~MissionPackage() {
    delete[] pacakge;
}
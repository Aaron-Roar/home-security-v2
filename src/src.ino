#include "/root/development/home-security2/src/sensors/task_list.h"

int hard;

void setup() {
Serial.begin(9600);


    //Exec, prio, period, periodic, deadl, dead_t, realease
    //ptr, ptr, interuptable, func_type

//updating hall effect states
    const struct TimeInfo t_info1 = createTInfo(1, 10, 4, 3, 1, 1, 0);
    const struct ExecConstraints ex_con1 = createExCons(NULL, NULL, 0, 1);
    const struct Job job1 = createJob(ex_con1, t_info1, 1);

//updating hall effect notification
    const struct TimeInfo t_info2 = createTInfo(1, 10, 4, 3, 1, 1, 0);
    const struct ExecConstraints ex_con2 = createExCons(NULL, NULL, 0, 2);
    const struct Job job2 = createJob(ex_con2, t_info2, 2);

//updating flood states
    const struct TimeInfo t_info3 = createTInfo(1, 10, 4, 3, 1, 1, 0);
    const struct ExecConstraints ex_con3 = createExCons(NULL, NULL, 0, 3);
    const struct Job job3 = createJob(ex_con3, t_info3, 3);

//updating flood notification
    const struct TimeInfo t_info4 = createTInfo(1, 10, 4, 3, 1, 1, 0);
    const struct ExecConstraints ex_con4 = createExCons(NULL, NULL, 0, 4);
    const struct Job job4 = createJob(ex_con4, t_info4, 4);

//updating laser state
    const struct TimeInfo t_info5 = createTInfo(1, 10, 4, 3, 1, 1, 0);
    const struct ExecConstraints ex_con5 = createExCons(NULL, NULL, 0, 5);
    const struct Job job5 = createJob(ex_con5, t_info5, 5);

//updating laser notification
    const struct TimeInfo t_info6 = createTInfo(1, 10, 4, 3, 1, 1, 0);
    const struct ExecConstraints ex_con6 = createExCons(NULL, NULL, 0, 6);
    const struct Job job6 = createJob(ex_con6, t_info6, 6);


//updating laser notification
    const struct TimeInfo t_info7 = createTInfo(1, 10, 4, 3, 1, 1, 0);
    const struct ExecConstraints ex_con7 = createExCons(NULL, NULL, 0, 7);
    const struct Job job7 = createJob(ex_con7, t_info7, 7);

//updating laser notification
    const struct TimeInfo t_info8 = createTInfo(1, 10, 4, 3, 1, 1, 0);
    const struct ExecConstraints ex_con8 = createExCons(NULL, NULL, 0, 8);
    const struct Job job8 = createJob(ex_con8, t_info8, 8);

//updating laser notification
    const struct TimeInfo t_info9 = createTInfo(1, 10, 4, 3, 1, 1, 0);
    const struct ExecConstraints ex_con9 = createExCons(NULL, NULL, 0, 9);
    const struct Job job9 = createJob(ex_con9, t_info9, 9);

    const struct TimeInfo t_info10 = createTInfo(1, 10, 4, 3, 1, 1, 0);
    const struct ExecConstraints ex_con10 = createExCons(NULL, NULL, 0, 10);
    const struct Job job10 = createJob(ex_con10, t_info10, 10);

    addInstruction(1, setHallStates);
    addInstruction(2, hallStateResponse);

    addInstruction(3, floodDetection);
    addInstruction(4, floodResponse);

    addInstruction(5, laser);
    addInstruction(6, isLaserTriped);

    addInstruction(7, update_psd);
    addInstruction(8, psd_light_indication);

    addInstruction(9, updateOrientation);
    addInstruction(10, evaluateEarthQuake);
    //Zeroing all lists
    zero();

    //Adding the tasks
    addTask(job1, que);
    addTask(job2, que);
    addTask(job3, que);
    addTask(job4, que);
    addTask(job5, que);
    addTask(job6, que);
    addTask(job7, que);
    addTask(job8, que);
    addTask(job9, que);
    addTask(job10, que);

    earthquakeInit();
    initHall();
    flood_init();
    laserInit();
    psd_init();

    //chacking if the schudle is feasible
    //printf("Is feasible: %d\n", schedulerFeasibilty());

    //setting the desired algorithms
    algorithm_full = edfFull;
    algorithm_next = edfFull;

    //Making a full jobs schedule from tasks
    fullSchedule();
    hard = 0;

}

void loop() {
    scheduleNext(hard);
    runNext();
}

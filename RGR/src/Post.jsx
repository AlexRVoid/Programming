import format from "date-fns/format";
import getDay from "date-fns/getDay";
import parse from "date-fns/parse";
import startOfWeek from "date-fns/startOfWeek";
import React, { useState } from "react";
import { Calendar, dateFnsLocalizer } from "react-big-calendar";
import "react-big-calendar/lib/css/react-big-calendar.css";
import DatePicker from "react-datepicker";
import "react-datepicker/dist/react-datepicker.css";
import './styles/app.css'
const Post = () => {
//     const [posts, setPosts]=useState([])
//     const[title,setTitle]=useState('')
//     const[start, setStart] = useState('')
//     const[deadline, setDeadline] = useState('')
//     const [completed, setCompleted] = useState([])
//     const clearPosts=()=>{
//         setPosts([])
//     }
//     const addList = () =>{
//         if (title !== '' && deadline !== ''){
//             setPosts([{task:title,dateStart: start, dateEnd: deadline ,id:Date.now(), completed:false},...posts])
//             setTitle('')
//             setStart('')
//             setDeadline('')
//             console.log(posts.task);
//
//         }
//     }
//     const changeCompleted = (id) => {
//         let copy = Object.assign([], completed);
//         copy[id] = !copy[id];
//         setCompleted(copy);
//     }
//
//     const dateCheck = (id) => {
//
//     }
//
//
//     return (
//         <div className="App">
//                 <h1 className="Name">Tasker</h1>
//
//                 <form className="Inputbox">
//
//                         <input value ={title} className="input" onChange={e=> setTitle(e.target.value)} type="text" id="task" placeholder="Введите вашу задачу" required/>
//
//                         <input value ={deadline} className="input" onChange={e=> setStart(e.target.value)} type="date" id="date" placeholder="Введите дату начала" required/>
//
//                         <input value ={deadline} className="input" onChange={e=> setDeadline(e.target.value)} type="date" id="date" placeholder="Введите дату окончания" required/>
//
//                         <div onClick={addList} className="submit">Добавить</div>
//
//                 </form>
//
            {
                posts.length ? (
                    <div>
                        <div className="Works">
                            {
                                posts.map((el, id) => <div onClick={() => changeCompleted(id)} className={completed[id]? "task completed" : "task"} key={id}>

                                    <h3>{el.task}</h3>
                                    <div className="task-meta">
                                        <img
                                            src="https://icongr.am/feather/calendar.svg?size=12&color=b5b5b5"
                                            alt="calendar"
                                        />
                                        {el.dateStart}
                                         :
                                        {el.dateEnd}
                                    </div>


                                </div>)
                            }
                        </div>
                    <div onClick={clearPosts} className="clearList" id="circ">Очистить</div>
                    </div>
                ) : ''

            }
//
//         </div>
//     );
// };
    const locales = {
        "en-US": require("date-fns/locale/en-US"),
    };
    const localizer = dateFnsLocalizer({
        format,
        parse,
        startOfWeek,
        getDay,
        locales,
    });

    const events = [
        {
            title: "Big Meeting",
            allDay: true,
            start: new Date(2021, 6, 0),
            end: new Date(2021, 6, 0),
        },
        {
            title: "Vacation",
            start: new Date(2021, 6, 7),
            end: new Date(2021, 6, 10),
        },
        {
            title: "Conference",
            start: new Date(2021, 6, 20),
            end: new Date(2021, 6, 23),
        },
    ];


        const [newEvent, setNewEvent] = useState({ title: "", start: "", end: "" });
        const [allEvents, setAllEvents] = useState(events);

        function handleAddEvent() {

            for (let i=0; i<allEvents.length; i++){

                const d1 = new Date (allEvents[i].start);
                const d2 = new Date(newEvent.start);
                const d3 = new Date(allEvents[i].end);
                const d4 = new Date(newEvent.end);
                /*
                    console.log(d1 <= d2);
                    console.log(d2 <= d3);
                    console.log(d1 <= d4);
                    console.log(d4 <= d3);
                      */

                if (
                    ( (d1  <= d2) && (d2 <= d3) ) || ( (d1  <= d4) &&
                        (d4 <= d3) )
                )
                {
                    alert("CLASH");
                    break;
                }

            }


            setAllEvents([...allEvents, newEvent]);
        }

        return (
            <div className="App">
                <h1>Calendar</h1>
                <h2>Add New Event</h2>
                <div>
                    <input type="text" placeholder="Add Title" style={{ width: "20%", marginRight: "10px" }} value={newEvent.title} onChange={(e) => setNewEvent({ ...newEvent, title: e.target.value })} />
                    <DatePicker placeholderText="Start Date" style={{ marginRight: "10px" }} selected={newEvent.start} onChange={(start) => setNewEvent({ ...newEvent, start })} />
                    <DatePicker placeholderText="End Date" selected={newEvent.end} onChange={(end) => setNewEvent({ ...newEvent, end })} />
                    <button stlye={{ marginTop: "10px" }} onClick={handleAddEvent}>
                        Add Event
                    </button>
                </div>
                <Calendar localizer={localizer} events={allEvents} startAccessor="start" endAccessor="end" style={{ height: 500, margin: "50px" }} />
            </div>
        );
    }

export default Post;
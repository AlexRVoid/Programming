import React, {useState} from 'react';
import './styles/app.css'
const Post = () => {
    const [posts, setPosts]=useState([])
    const[title,setTitle]=useState('')
    const[deadline, setDeadline] = useState('')
    const [completed, setCompleted] = useState([])
    const clearPosts=()=>{
        setPosts([])
    }
    const addList = () =>{
        if (title !== '' && deadline !== ''){
            setPosts([{task:title,date:deadline,id:Date.now(), completed:false},...posts])
            setTitle('')
            setDeadline('')
            console.log(posts.task);

        }
    }
    const changeCompleted = (id) => {
        let copy = Object.assign([], completed);
        copy[id] = !copy[id];
        setCompleted(copy);
    }

    const dateCheck = (id) => {

    }


    return (
        <div className="App">
                <h1 className="Name">Tasker</h1>

                <form className="Inputbox">

                        <input value ={title} className="input" onChange={e=> setTitle(e.target.value)} type="text" id="task" placeholder="Введите вашу задачу" required/>


                        <input value ={deadline} className="input" onChange={e=> setDeadline(e.target.value)} type="date" id="date" placeholder="Введите дату" required/>

                        <div onClick={addList} className="submit">Добавить</div>

                </form>
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
                                        {el.date}
                                    </div>


                                </div>)
                            }
                        </div>
                    <div onClick={clearPosts} className="clearList" id="circ">Очистить</div>
                    </div>
                ) : ''

            }

        </div>
    );
};

export default Post;